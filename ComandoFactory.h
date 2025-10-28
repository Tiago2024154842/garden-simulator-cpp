#ifndef COMANDOFACTORY_H
#define COMANDOFACTORY_H

#include "Comandos/Comando.h"

class ComandoFactory {
public:
    static Comando * criarComando(const std::string & comando);
};

#endif
