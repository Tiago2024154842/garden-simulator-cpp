cmake_minimum_required(VERSION 3.30)
project(trabalhopratico)

set(CMAKE_CXX_STANDARD 20)

add_executable(trabalhopratico main.cpp
        Comando.cpp
        Comando.h
        ComandoFactory.cpp
        ComandoFactory.h
        Jardim.cpp
        Jardim.h)
