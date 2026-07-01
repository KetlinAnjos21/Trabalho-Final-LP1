cmake_minimum_required(VERSION 3.10)

project(ControladorDeViagens)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(ControladorDeViagens

    src/main.cpp

    src/Cidade.cpp
    src/Trajeto.cpp
    src/Transporte.cpp
    src/Passageiro.cpp
    src/Viagem.cpp
    src/ControladorDeTransito.cpp

)

