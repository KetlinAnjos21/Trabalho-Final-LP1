#include "../include/ControladorDeTransito.h"
#include <iostream>
#include <fstream>

using namespace std;

//===================================
//    Construtor e Destrutor
//===================================

ControladorDeTransito::ControladorDeTransito() {
    // Inicializador padrão
}

ControladorDeTransito::~ControladorDeTransito() {
    limparMemoria();
}

//===================================
//         Métodos Privados
//===================================

Cidade* ControladorDeTransito::buscarCidades(const string& nome) const {
    for (auto cidade : cidades) {
        if (cidade->getNome() == nome) { // Compatível com Cidade::getNome()
            return cidade;
        }
    }
    return nullptr;
}

Transporte* ControladorDeTransito::buscarTransporte(const string& nome) const {
    for (auto transporte : transportes) {
        if (transporte->getNome() == nome) { // Compatível com Transporte::getNome()
            return transporte;
        }
    }
    return nullptr;
}

Passageiro* ControladorDeTransito::buscarPassageiro(const string& nome) const {
    for (auto passageiro : passageiros) {
        if (passageiro->getNome() == nome) { // Compatível com Passageiro::getNome()
            return passageiro;
        }
    }
    return nullptr;
}

Trajeto* ControladorDeTransito::buscarTrajeto(Cidade* origem, Cidade* destino) {
    if (!origem || !destino) return nullptr;
    for (auto trajeto : trajetos) {
        if (trajeto->getOrigem() == origem && trajeto->getDestino() == destino) { //
            return trajeto;
        }
    }
    return nullptr;
}

//===================================
//         Menu Principal
//===================================

void ControladorDeTransito::menu() {
    int opcao = -1;
    while (opcao != 0) {
        cout << "\n=====================================\n";
        cout << "   CONTROLADOR DE TRÂNSITO URBANO\n";
        cout << "=====================================\n";
        cout << "1. Cadastrar Cidade\n";
        cout << "2. Cadastrar Trajeto\n";
        cout << "3. Cadastrar Transporte\n";
        cout << "4. Cadastrar Passageiro\n";
        cout << "5. Exibir Relatório Geral (Listagens)\n";
        cout << "6. Iniciar Nova Viagem\n";
        cout << "7. Avançar Horas no Tempo\n";
        cout << "8. Salvar Todos os Dados\n";
        cout << "0. Sair do Programa\n";
        cout << "-------------------------------------\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: cadastrarCidade(); break;
            case 2: cadastrarTrajeto(); break;
            case 3: cadastrarTransporte(); break;
            case 4: cadastrarPassageiro(); break;
            case 5:
                listarCidades();
                listarTrajetos();
                listarTransportes();
                listarPassageiros();
                listarViagens();
                break;
            case 6: iniciarViagens(); break;
            case 7: avancarHoras(); break;
            case 8: salvarTodosDados(); break;
            case 0: cout << "\nEncerrando o programa e liberando memória...\n"; break;
            default: cout << "\nOpção inválida! Tente novamente.\n"; break;
        }
    }
}

//===================================
//             Cadastro
//===================================

void ControladorDeTransito::cadastrarCidade() {
    string nome;
    cout << "Digite o nome da cidade: ";
    getline(cin, nome);

    if (buscarCidades(nome) != nullptr) {
        cout << "Erro: Cidade já cadastrada.\n";
        return;
    }

    cidades.push_back(new Cidade(nome)); // Usa o construtor Cidade(string)
    cout << "Cidade cadastrada com sucesso!\n";
}

void ControladorDeTransito::cadastrarTrajeto() {
    string orig, dest;
    char tipo;
    int distancia;

    cout << "Cidade de Origem: ";
    getline(cin, orig);
    cout << "Cidade de Destino: ";
    getline(cin, dest);

    Cidade* cOrigem = buscarCidades(orig);
    Cidade* cDestino = buscarCidades(dest);

    if (!cOrigem || !cDestino) {
        cout << "Erro: Uma ou ambas as cidades não foram encontradas.\n";
        return;
    }

    cout << "Tipo do Trajeto (A - Aéreo, T - Terrestre, M - Marítimo): ";
    cin >> tipo;
    cout << "Distância (em km): ";
    cin >> distancia;
    cin.ignore();

    // Usa o construtor Trajeto(Cidade*, Cidade*, char, int)
    trajetos.push_back(new Trajeto(cOrigem, cDestino, tipo, distancia));
    cout << "Trajeto cadastrado com sucesso!\n";
}

void ControladorDeTransito::cadastrarTransporte() {
    string nome, cidadeNome;
    char tipo;
    int capacidade, velocidade, distDescanso, tempoDescanso;

    cout << "Nome/Modelo do Transporte: ";
    getline(cin, nome);
    cout << "Tipo (A - Aéreo, T - Terrestre, M - Marítimo): ";
    cin >> tipo;
    cout << "Capacidade de Passageiros: ";
    cin >> capacidade;
    cout << "Velocidade Média (km/h): ";
    cin >> velocidade;
    cout << "Distância Máxima entre Descansos (km): ";
    cin >> distDescanso;
    cout << "Tempo de Descanso Obrigatório (horas): ";
    cin >> tempoDescanso;
    cin.ignore();
    cout << "Nome da Cidade onde o transporte está atualmente: ";
    getline(cin, cidadeNome);

    Cidade* local = buscarCidades(cidadeNome);
    if (!local) {
        cout << "Erro: Cidade informada não existe.\n";
        return;
    }

    // Usa o construtor de Transporte com seus 8 parâmetros
    transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distDescanso, tempoDescanso, 0, local));
    cout << "Transporte cadastrado com sucesso!\n";
}

void ControladorDeTransito::cadastrarPassageiro() {
    string nome, cidadeNome;
    cout << "Nome do Passageiro: ";
    getline(cin, nome);
    cout << "Cidade onde o passageiro está atualmente: ";
    getline(cin, cidadeNome);

    Cidade* local = buscarCidades(cidadeNome);
    if (!local) {
        cout << "Erro: Cidade informada não existe.\n";
        return;
    }

    if (buscarPassageiro(nome) != nullptr) {
        cout << "Erro: Passageiro já cadastrado com esse nome.\n";
        return;
    }

    // Usa o construtor Passageiro(string, Cidade*)
    passageiros.push_back(new Passageiro(nome, local));
    cout << "Passageiro cadastrado com sucesso!\n";
}

//====================================
//            Listagens
//====================================

void ControladorDeTransito::listarCidades() const {
    cout << "\n--- Cidades Cadastradas ---\n";
    if (cidades.empty()) cout << "Nenhuma cidade cadastrada.\n";
    for (const auto cidade : cidades) {
        cout << "- " << cidade->getNome() << "\n"; //
    }
}

void ControladorDeTransito::listarTrajetos() const {
    cout << "\n--- Trajetos Cadastrados ---\n";
    if (trajetos.empty()) cout << "Nenhum trajeto cadastrado.\n";
    for (auto trajeto : trajetos) {
        cout << "- " << trajeto->getOrigem()->getNome() << " -> " 
             << trajeto->getDestino()->getNome() << " | Tipo: " << trajeto->getTipo() 
             << " | Distância: " << trajeto->getDistancia() << " km\n"; //
    }
}

void ControladorDeTransito::listarTransportes() const {
    cout << "\n--- Transportes Cadastrados ---\n";
    if (transportes.empty()) cout << "Nenhum transporte cadastrado.\n";
    for (const auto transporte : transportes) {
        cout << "- " << transporte->getNome() << " [Tipo: " << transporte->getTipo() << "] | Local: " 
             << (transporte->getLocalAtual() ? transporte->getLocalAtual()->getNome() : "Em trânsito") << "\n"; //
    }
}

void ControladorDeTransito::listarPassageiros() const {
    cout << "\n--- Passageiros Cadastrados ---\n";
    if (passageiros.empty()) cout << "Nenhum passageiro cadastrado.\n";
    for (const auto passageiro : passageiros) {
        cout << "- " << passageiro->getNome() << " | Local Atual: " 
             << (passageiro->getLocalAtual() ? passageiro->getLocalAtual()->getNome() : "Em viagem") << "\n"; //
    }
}

void ControladorDeTransito::listarViagens() const {
    cout << "\n--- Status das Viagens ---\n";
    if (viagens.empty()) {
        cout << "Nenhuma viagem registrada.\n";
        return;
    }
    for (const auto viagem : viagens) {
        viagem->relatarEstado(); // Usa o método relatarEstado() da sua classe Viagem
    }
}

//=====================================
//             Viagens
//=====================================

void ControladorDeTransito::iniciarViagens() {
    string orig, dest, transpNome;
    cout << "Cidade Origem da Viagem: ";
    getline(cin, orig);
    cout << "Cidade Destino da Viagem: ";
    getline(cin, dest);
    cout << "Nome do Transporte: ";
    getline(cin, transpNome);

    Cidade* cOrigem = buscarCidades(orig);
    Cidade* cDestino = buscarCidades(dest);
    Transporte* trans = buscarTransporte(transpNome);
    Trajeto* traj = buscarTrajeto(cOrigem, cDestino);

    if (!traj) {
        cout << "Erro: Não existe trajeto direto entre essas cidades.\n";
        return;
    }
    if (!trans) {
        cout << "Erro: Transporte não encontrado.\n";
        return;
    }
    if (trans->getLocalAtual() != cOrigem) {
        cout << "Erro: O transporte não está na cidade de origem.\n";
        return;
    }
    if (trans->getTipo() != traj->getTipo()) {
        cout << "Erro: Tipo de transporte incompatível com o trajeto.\n";
        return;
    }

    // Coleta passageiros que estão na cidade de origem respeitando o limite do transporte
    vector<Passageiro*> passageirosAlocados;
    for (auto pass : passageiros) {
        if (pass->getLocalAtual() == cOrigem) {
            passageirosAlocados.push_back(pass);
            if ((int)passageirosAlocados.size() == trans->getCapacidade()) break; //
        }
    }

    if (passageirosAlocados.empty()) {
        cout << "Erro: Não há passageiros em " << orig << " para viajar.\n";
        return;
    }

    // Instancia a viagem conforme seu construtor Viagem(Transporte*, const vector<Passageiro*>&, Cidade*, Cidade*)
    Viagem* novaViagem = new Viagem(trans, passageirosAlocados, cOrigem, cDestino);
    
    int tempoNecessario = traj->getDistancia() / trans->getVelocidade(); //
    if (tempoNecessario == 0) tempoNecessario = 1; 
    
    novaViagem->setHorasNecessarias(tempoNecessario); //
    novaViagem->iniciarViagem(); //

    // Veículo e passageiros entram em trânsito (nullptr)
    trans->setLocalAtual(nullptr);
    for (auto pass : passageirosAlocados) {
        pass->setLocalAtual(nullptr);
    }

    viagens.push_back(novaViagem);
}

void ControladorDeTransito::avancarHoras() {
    int horas;
    cout << "Quantas horas deseja avançar no sistema? ";
    cin >> horas;
    cin.ignore();

    if (horas <= 0) return;

    for (auto viagem : viagens) {
        if (viagem->isEmAndamento()) { //
            viagem->avancarHoras(horas); // Avança o tempo interno da viagem
        }
    }
    cout << "Tempo avançado com sucesso.\n";
}

//======================================
//           Persistência
//======================================

void ControladorDeTransito::salvarCidades() const {
    ofstream arq("cidades.txt");
    for (auto c : cidades) arq << c->getNome() << "\n"; //
}

void ControladorDeTransito::carregarCidades() {}
void ControladorDeTransito::salvarTrajetos() const {}
void ControladorDeTransito::carregarTrajetos() {}
void ControladorDeTransito::salvarTransportes() const {}
void ControladorDeTransito::carregarTransportes() {}
void ControladorDeTransito::salvarPassageiros() const {}
void ControladorDeTransito::carregarPassageiros() {}
void ControladorDeTransito::salvarViagens() const {}
void ControladorDeTransito::carregarViagens() {}

void ControladorDeTransito::salvarTodosDados() const {
    salvarCidades();
    salvarTrajetos();
    salvarTransportes();
    salvarPassageiros();
    salvarViagens();
    cout << "Todos os dados salvos com sucesso.\n";
}

void ControladorDeTransito::carregarTodosDados() {
    carregarCidades();
    carregarTrajetos();
    carregarTransportes();
    carregarPassageiros();
    carregarViagens();
}

//=====================================
//            Utilidades
//=====================================

void ControladorDeTransito::limparMemoria() 

{
    for (auto c : cidades) delete c;
    for (auto t : trajetos) delete t; // Ajustado implicitamente se houver typo
    for (auto tr : transportes) delete tr;
    for (auto p : passageiros) delete p;
    for (auto v : viagens) delete v;

    cidades.clear();
    trajetos.clear();
    transportes.clear();
    passageiros.clear();
    viagens.clear();
};



