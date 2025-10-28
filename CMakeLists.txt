cmake_minimum_required(VERSION 3.30)
project(trabalhopratico)

set(CMAKE_CXX_STANDARD 20)

add_executable(trabalhopratico main.cpp
        Comandos/Comando.cpp
        Comandos/Comando.h
        ComandoFactory.cpp
        ComandoFactory.h
        Jardim/Planta.cpp
        Jardim/Planta.h
)
