#include "../include/Transporte.h"
#include "../include/Cidade.h"

Transporte::Transporte() {
    
    nome = "";
    tipo = 'T';
    capacidade = 0;
    velocidade = 0;
    distanciaEntreDescanso = 0;
    tempoDeDescanso = 0;
    tempoDeDescansoAtual = 0;
    localAtual = nullptr;
}


Transporte::Transporte(const std::string& nome,
                        
                    char tipo,
                    int capacidade,
                    int velocidade,
                    int distanciaEntreDescanso,
                    int tempoDeDescanso,
                    int tempoDeDescansoAtual,
                    Cidade* localAtual) {


this->nome = nome;
this->tipo = tipo;
this->capacidade = capacidade;
this->velocidade = velocidade;
this->distanciaEntreDescanso = distanciaEntreDescanso;
this->tempoDeDescanso = tempoDeDescanso;
this->tempoDeDescansoAtual = 0;
this->localAtual = localAtual;

}

std::string Transporte::getNome() const {
    return nome;
}

char Transporte::getTipo() const {
    return tipo;
}

int Transporte::getCapacidade() const {
    return capacidade;
}

int Transporte::getVelocidade() const {
    return velocidade;
}

int Transporte::getDistanciaEntreDescansos() const {
    return distanciaEntreDescanso;
}

int Transporte::getTempoDeDescanso() const {
    return tempoDeDescanso;
}

int Transporte::getTempoDeDescansoAtual() const {
    return tempoDeDescansoAtual;
}

Cidade* Transporte::getLocalAtual() const {
    return localAtual;
}



void Transporte::setNome(const std::string& nome) {
    this->nome = nome;
}

void Transporte::setTipo(char tipo) {
    this->tipo = tipo;
}

void Transporte::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

void Transporte::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

void Transporte::setDistanciaEntreDescanso(int distancia) {
    this->distanciaEntreDescanso = distancia;
}

void Transporte::setTempoDeDescanso(int descanso) {
    this->tempoDeDescanso = descanso;
}

void Transporte::setTempoDeDescansoAtual(int tempo) {
    this->tempoDeDescansoAtual = tempo;
}

void Transporte::setLocalAtual(Cidade* local) {
    this->localAtual = local;
}


