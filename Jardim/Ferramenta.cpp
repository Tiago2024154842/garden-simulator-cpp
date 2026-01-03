#include "Ferramenta.h"
#include "Settings.h"
#include "Celula.h"
#include <sstream>

int Ferramenta::contadorNumSerie = 0;

Ferramenta::Ferramenta(const char s, const std::string & n) : simbolo(s), nome(n) {
    numSerie = ++contadorNumSerie;
}

int Ferramenta::getNumSerie() const {
    return numSerie;
}

char Ferramenta::getSimbolo() const {
    return simbolo;
}

std::string Ferramenta::getNome() const {
    return nome;
}

Regador::Regador() : Ferramenta('g', "Regador"), agua(Settings::Regador::capacidade) {}

Regador * Regador::copia() const {
    return new Regador(*this);
}

void Regador::usar(Celula* area) {
    if (area != nullptr && agua >= 10) {
        // area->adicionarAgua(Settings::Regador::dose); 
        agua -= Settings::Regador::dose;
    }
}

std::string Regador::getDesc() const {
    std::ostringstream str;
    str << getNome() << " (nr de serie: " << getNumSerie() << ") com " << agua << " de agua e " << agua/2 << "% de capacidade";
    return str.str();
}

Adubo::Adubo() : Ferramenta('a', "Pacote de adubo"), quantidade(Settings::Adubo::capacidade) {}

Adubo * Adubo::copia() const {
    return new Adubo(*this);
}

void Adubo::usar(Celula* area) {
    if (area != nullptr && quantidade >= 10) {
        // area->adicionarNutrientes(10);
        quantidade -= Settings::Adubo::dose;
    }
}

std::string Adubo::getDesc() const {
    std::ostringstream str;
    str << getNome() << " (nr de serie: " << getNumSerie() << ") com " << quantidade << " unidades de adubo e " << (quantidade*100)/Settings::Adubo::capacidade << "% de capacidade";
    return str.str();
}

Tesoura::Tesoura() : Ferramenta('t', "Tesoura de poda") {}

Tesoura * Tesoura::copia() const {
    return new Tesoura(*this);
}

void Tesoura::usar(Celula* area) {
    if (area != nullptr && area->temPlanta()) {
        area->removerPlanta();
    }
}

std::string Tesoura::getDesc() const {
    std::ostringstream str;
    str << getNome() << " (nr de serie: " << getNumSerie() << ")";
    return str.str();
}

Enxada::Enxada() : Ferramenta('z', "Enxada") {}

Enxada * Enxada::copia() const {
    return new Enxada(*this);
}

void Enxada::usar(Celula* area) {}

std::string Enxada::getDesc() const {
    std::ostringstream str;
    str << getNome() << " (nr de serie: " << getNumSerie() << ")";
    return str.str();
}
