#include "ComandoFactory.h"

Comando * ComandoFactory::criarComando(const std::string & comando) {
    if (comando == "lplantas") return new lplantas();
    if (comando == "planta") return new planta();
    if (comando == "lplanta") return new lplanta();
    if (comando == "avanca") return new avanca();
    return nullptr;
}