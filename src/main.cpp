//=========================================================
// Projeto: Controlador de Viagens
// Arquivo: main.cpp
//=========================================================

#include <iostream>

#include "../include/ControladorDeTransito.h"

using namespace std;

int main() {

    ControladorDeTransito sistema;

    cout << "==========================================" << endl;
    cout << "      CONTROLADOR DE VIAGENS" << endl;
    cout << "==========================================" << endl;

    // Carrega os dados salvos anteriormente
    sistema.carregarTodosDados();

    // Executa o menu principal
    sistema.menu();

    // Salva todos os dados antes de encerrar
    sistema.salvarTodosDados();

    cout << "\n==========================================" << endl;
    cout << "Obrigado por utilizar o sistema!" << endl;
    cout << "==========================================" << endl;

    return 0;
} 

