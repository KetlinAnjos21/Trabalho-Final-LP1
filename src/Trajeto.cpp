#include"../include/Trajeto.h"

Trajeto::Trajeto(Cidade* origem,
                Cidade* destino,
                char tipo,
                int distancia) {

        this->origem = origem;
        this->destino = destino;
        this->tipo = tipo;
        this->distancia = distancia;
}


Cidade* Trajeto::getOrigem() const {
    return origem;
}

Cidade* Trajeto::getDestino() const {
    return destino;
}

char Trajeto::getTipo() const {
    return tipo;
}

int Trajeto::getDistancia() const {
    return distancia;
}

