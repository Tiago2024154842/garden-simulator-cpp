#include "ComandoFactory.h"

Comando * ComandoFactory::criarComando(const std::string & comando) {
    if (comando == "lplantas") return new lplantas();
    if (comando == "planta") return new planta();
    return nullptr;
}