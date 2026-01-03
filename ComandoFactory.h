#ifndef COMANDOFACTORY_H
#define COMANDOFACTORY_H

#include <unordered_map>
#include "Comandos/Comando.h"
#include "Jardim/Jardim.h"

class ComandoFactory {
  public:
    static Jardim * executarComando(const std::string& c, Jardim* jardimAtual);
    static void gravar(const std::string & nome, Jardim* jardimAtual);
    static bool recuperar(const std::string & nome, Jardim* jardimAtual);
    static bool apagar(const std::string & nome);

  private:
    static std::unordered_map<string, Jardim*> gravacoes;
    static Comando * criarComando(const std::string & comando);
};

#endif
