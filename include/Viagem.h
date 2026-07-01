#ifndef VIAGEM_H
#define VIAGEM_H


#include <vector>
#include <string>


class Transporte;
class Passageiro;
class Cidade;

class Viagem {

    private:

        Transporte* transporte;
        std::vector<Passageiro*> passageiro;

        Cidade* origem;
        Cidade* destino;

        Viagem* proxima;

        int horasEmTransito;
        int horasNecessarias;

        bool emAndamento;
        bool finalizada;


    public: 

        Viagem();

        Viagem(Transporte* transporte,
                const std::vector<Passageiro*>& passageiro,
                Cidade* origem,
                Cidade* destino);

        void iniciarViagem();
        void avancarHoras(int horas);
        void finalizarViagem();

        void relatarEstado() const;

        Transporte* getTransporte() const;
        Cidade* getOrigem() const;
        Cidade* getDestino() const;

        std::vector<Passageiro*> getPassageiro() const;

        int getHorasEmTransito() const;
        int getHorasNecessarias() const;

        bool isEmAndamento() const;
        bool isFinalizada() const;

        Viagem* getProxima() const;

        void setHorasNecessarias(int horas);
        void setProxima(Viagem* proxima);

};


#endif