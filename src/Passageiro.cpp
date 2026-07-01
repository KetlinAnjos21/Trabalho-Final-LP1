#include "../include/Passageiro.h"
#include "../include/Cidade.h"


Passageiro::Passageiro() {

    nome = "";
    localAtual = nullptr;
}

Passageiro::Passageiro(const std::string& nome,
                        Cidade* localAtual) {


            this->nome = nome;
            this->localAtual = localAtual;

}

std::string Passageiro::getNome() const {
    return nome;
}

Cidade* Passageiro::getLocalAtual() const {
    return localAtual;
}

void Passageiro::setNome(const std::string& nome) {
    this->nome = nome;
}

void Passageiro::setLocalAtual(Cidade* localAtual) {
    this->localAtual = localAtual;
}