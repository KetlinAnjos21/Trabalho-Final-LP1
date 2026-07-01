#ifndef CONTROLADORDETRANSITO_H
#define CONTROLADORDETRANSITO_H

#include <vector>
#include <string>

#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"

class ControladorDeTransito {

    private:
        std::vector<Cidade*> cidades;
        std::vector<Trajeto*> trajetos;
        std::vector<Transporte*> transportes;
        std::vector<Passageiro*> passageiros;
        std::vector<Viagem*> viagens;

        Cidade* buscarCidades(const std::string& nome) const;
        Transporte* buscarTransporte(const std::string& nome) const;
        Passageiro* buscarPassageiro(const std::string& nome) const;
        Trajeto* buscarTrajeto(Cidade* origem, Cidade* destino); 

    public:
        ControladorDeTransito();
        ~ControladorDeTransito();

        void menu();

        void cadastrarCidade();
        void cadastrarTrajeto();
        void cadastrarTransporte();
        void cadastrarPassageiro();

        void listarCidades() const;
        void listarTrajetos() const;
        void listarTransportes() const;
        void listarPassageiros() const;
        void listarViagens() const;

        void iniciarViagens();
        void avancarHoras();

        void salvarCidades() const;
        void carregarCidades(); 
        void salvarTrajetos() const;
        void carregarTrajetos(); 
        void salvarTransportes() const;
        void carregarTransportes(); 
        void salvarPassageiros() const;
        void carregarPassageiros(); 
        void salvarViagens() const;
        void carregarViagens(); 
        void salvarTodosDados() const;
        void carregarTodosDados(); 

        void limparMemoria();
};

#endif


