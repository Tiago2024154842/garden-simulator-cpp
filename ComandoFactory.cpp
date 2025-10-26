#include "ComandoFactory.h"

Comando * ComandoFactory::criarComando(const std::string & comando) {
    if (comando == "lplantas") return new Lplantas();
    if (comando == "jardim") return new Jardim();
    return nullptr;
}