cmake_minimum_required(VERSION 3.30)
project(Trabalho_POO)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Trabalho_POO main.cpp
        Comandos/Comando.cpp
        Comandos/Comando.h
        ComandoFactory.cpp
        ComandoFactory.h
        Jardim/Planta.cpp
        Jardim/Planta.h
        Jardim/Jardim.cpp
        Jardim/Jardim.h
        Jardim/Celula.cpp
        Jardim/Celula.h
        Random/Random.h
        Random/Random.cpp
        Jardim/Ferramenta.h
        Jardim/Ferramenta.cpp
        Jardim/Jardineiro.cpp
        Jardim/Jardineiro.h
)
