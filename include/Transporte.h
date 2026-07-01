#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string>

class Cidade;

class Transporte {

    private:
        
        std::string nome;
        char tipo; 
        int capacidade;
        int velocidade;
        int distanciaEntreDescanso;
        int tempoDeDescanso;
        int tempoDeDescansoAtual;
        Cidade* localAtual;

    public:

        Transporte();

        Transporte(const std::string& nome,
                char tipo,
                int capacidade,
                int velocidade,
                int distanciaEntreDescanso,
                int tempoDeDescanso,
                int tempoDeDescansoAtual,
                Cidade* localAtual);

    std::string getNome() const;

                char getTipo() const;
                int getCapacidade() const;
                int getVelocidade() const;
                int getDistanciaEntreDescansos() const;
                int getTempoDeDescanso() const;
                int getTempoDeDescansoAtual() const;
                Cidade* getLocalAtual() const;

                void setNome(const std::string& nome);
                void setTipo(char tipo);
                void setCapacidade( int capacidade);
                void setVelocidade(int velocidade);
                void setDistanciaEntreDescanso(int distanciaEntreDescanso);
                void setTempoDeDescanso(int tempo);
                void setTempoDeDescansoAtual(int tempoDeDescansoAtual);
                void setLocalAtual(Cidade* local);



};

#endif