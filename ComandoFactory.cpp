#include "ComandoFactory.h"

Comando * ComandoFactory::criarComando(const std::string & comando) {
    if (comando == "lplantas") return new lplantas();
    if (comando == "planta") return new planta();
    if (comando == "lplanta") return new lplanta();
    if (comando == "avanca") return new avanca();
    if (comando == "larea") return new larea();
    if (comando == "lsolo") return new lsolo();
    if (comando == "lferr") return new lferr();
    if (comando == "colhe") return new colhe();
    if (comando == "larga") return new larga();
    if (comando == "pega") return new pega();
    if (comando == "e") return new movEsquerda();
    if (comando == "d") return new movDireita();
    if (comando == "c") return new movCima();
    if (comando == "b") return new movBaixo();
    if (comando == "entra") return new entra();
    if (comando == "sai") return new sai();
    if (comando == "grava") return new grava();
    if (comando == "recupera") return new recupera();
    if (comando == "apaga") return new apaga();
    if (comando == "executa") return new executa();
    return nullptr;
}