#ifndef COMANDOFACTORY_H
#define COMANDOFACTORY_H

#include "Comandos/Comando.h"

class ComandoFactory {
  public:
    static Jardim * executarComando(const string& c, Jardim* jardimAtual);
  private:
    static Comando * criarComando(const std::string & comando);
};

#endif
