#include "Ferramenta.h"
#include "Settings.h"
#include "Celula.h"
#include <sstream>

int Ferramenta::contadorNumSerie = 0;

Ferramenta::Ferramenta(char s) : simbolo(s) {
    numSerie = ++contadorNumSerie;
}

int Ferramenta::getNumSerie() const {
    return numSerie;
}

char Ferramenta::getSimbolo() const {
    return simbolo;
}

Regador::Regador() : Ferramenta('g'), agua(Settings::Regador::capacidade) {}

void Regador::usar(Celula* area) {
    if (area != nullptr && agua >= 10) {
        // area->adicionarAgua(Settings::Regador::dose); 
        agua -= Settings::Regador::dose;
    }
}

std::string Regador::getDesc() const {
    std::ostringstream str;
    str << "Regador -> Agua: " << agua << ", Capacidade: " << agua/2 << "%";
    return str.str();
}

Adubo::Adubo() : Ferramenta('a'), quantidade(Settings::Adubo::capacidade) {}

void Adubo::usar(Celula* area) {
    if (area != nullptr && quantidade >= 10) {
        // area->adicionarNutrientes(10);
        quantidade -= Settings::Adubo::dose;
    }
}

std::string Adubo::getDesc() const {
    std::ostringstream str;
    str << "Pacote de adubo -> Unidades de adubo: " << quantidade << ", Capacidade: " << (quantidade*100)/Settings::Adubo::capacidade << "%";
    return str.str();
}

Tesoura::Tesoura() : Ferramenta('t') {}

void Tesoura::usar(Celula* area) {
    if (area != nullptr && area->temPlanta()) {
        area->removePlanta();
    }
}

std::string Tesoura::getDesc() const {
    std::ostringstream str;
    str << "Tesoura de poda";
    return str.str();
}

Enxada::Enxada() : Ferramenta('z') {}

void Enxada::usar(Celula* area) {}

std::string Enxada::getDesc() const {
    std::ostringstream str;
    str << "Enxada";
    return str.str();
}
