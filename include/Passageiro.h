#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>

class Cidade;

class Passageiro {

    private:

        std::string nome;
        Cidade* localAtual;

    public:

        Passageiro();

        Passageiro(const std::string& nome, 
                    Cidade* localAtual);
        
        std::string getNome() const;
        Cidade* getLocalAtual() const;

        void setNome(const std::string& nome);
        void setLocalAtual(Cidade* localAtual);
};

#endif