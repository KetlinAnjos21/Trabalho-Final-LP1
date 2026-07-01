#include "../include/Viagem.h"
#include "../include/Transporte.h"
#include "../include/Passageiro.h"
#include "../include/Cidade.h"

#include <iostream>

using namespace std;

//==============================
// Construtor Padrão
//==============================

Viagem::Viagem() {

    transporte = nullptr;
    origem  = nullptr;
    destino = nullptr;
    proxima = nullptr;

    horasEmTransito = 0;
    finalizada = 0;

    emAndamento = false;
    finalizada = false;

}

//================================
// Construtor com Parâmetro
//================================


Viagem::Viagem(Transporte* transporte,
                const vector<Passageiro*>& passageiros,
                Cidade* origem,
                Cidade* destino) {
            
        
        this->transporte = transporte;
        this->passageiro = passageiros;
        this->origem = origem;
        this->destino = destino;
    
}

//====================================
// Iniciar Viagem
//====================================


void Viagem::iniciarViagem() {


    emAndamento = true;

    cout <<"\nViagem iniciada com sucesso!\n";
}

//====================================
//  Avançar Horas
//====================================


void Viagem::avancarHoras(int horas) {

    if(!emAndamento)
    return;

    horasEmTransito += horas;

    if(horasEmTransito >= horasNecessarias) {
        finalizarViagem();
    }

}

//======================================
//   Finalizar Viagem
//======================================


void Viagem::finalizarViagem() {

    emAndamento = false;
    finalizada = true;

    if(transporte != nullptr) {
        transporte->setLocalAtual(destino);
    }

    for(Passageiro* passageiro : passageiro) {

        passageiro->setLocalAtual(destino);
    }

    cout << "\nViagem finalizada!\n";
}


//========================================
//   Relatório
//========================================

void Viagem::relatarEstado() const {

    cout <<"\n====== Viagem =======\n";

    cout << "Origem : ";

    if(origem != nullptr)
        cout << origem->getNome();

    cout << "\nDestino: ";

    if(destino != nullptr)
        cout << destino->getNome();

    cout << "\nTransporte: ";

    if(transporte != nullptr)
        cout << transporte->getNome();

    cout <<"\nPassageiros: " << passageiro.size();

    cout << "\nHoras em Trânsito: "
         << horasEmTransito
         << "/"
         << horasNecessarias;

    cout << "\nStatus> ";

    if(finalizada)
        cout << "Finalizada";

    else if(emAndamento)
        cout << "Em andamento";

    else 
        cout << "Aguardando";

    cout <<endl;
}


//=======================================
//   Gets
//=======================================

Transporte* Viagem::getTransporte() const {
    return transporte;
}

Cidade* Viagem::getOrigem() const {
    return origem;
}

Cidade* Viagem::getDestino() const {
    return destino;
}

int Viagem::getHorasEmTransito() const {
    return horasEmTransito;
}

int Viagem::getHorasNecessarias() const {
    return horasNecessarias;
}

bool Viagem::isEmAndamento() const {
    return emAndamento;
}

bool Viagem::isFinalizada() const {
    return finalizada;
}

Viagem* Viagem::getProxima() const {
    return proxima;
}

//========================================
//   Sets
//========================================


void Viagem::setHorasNecessarias(int horas) {
    horasNecessarias = horas;
}

void Viagem::setProxima(Viagem* proxima) {
    this->proxima = proxima;
}

