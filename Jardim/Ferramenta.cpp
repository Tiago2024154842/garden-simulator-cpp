#include "Ferramenta.h"
#include "Settings.h"
#include "Celula.h"
#include <sstream>

int Ferramenta::contadorNumSerie = 0;

Ferramenta::Ferramenta(const char s, const std::string & n) : simbolo(s), nome(n) {
    numSerie = ++contadorNumSerie;
}

int Ferramenta::getNumSerie() const { return numSerie; }

char Ferramenta::getSimbolo() const { return simbolo; }

std::string Ferramenta::getNome() const {
    return nome;
}

Regador::Regador() : Ferramenta('g', "Regador"), agua(Settings::Regador::capacidade) {}

Regador * Regador::copia() const {
    return new Regador(*this);
}

bool Regador::usar(Celula* c) {
    if (c != nullptr && agua >= 10) {
        c->adicionarAgua(Settings::Regador::dose); 
        agua -= Settings::Regador::dose;
        if (agua < 0) agua = 0;

        std::cout << "O jardineiro usou o " << getNome() << std::endl;
    }

    return true;
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

bool Adubo::usar(Celula* c) {
    if (c != nullptr && quantidade >= 10) {
        c->adicionarNutrientes(Settings::Adubo::dose);
        quantidade -= Settings::Adubo::dose;
        if (quantidade < 0) quantidade = 0;

        std::cout << "O jardineiro usou o " << getNome() << " e ficou com " << (quantidade*100)/Settings::Adubo::capacidade 
            << "% do pacote cheio" << std::endl;
    }

    return true;
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

bool Tesoura::usar(Celula* c) {
    if (c != nullptr && c->temPlanta()) {
        Planta * p = c->getPlanta();

        if (p->getBeleza() == "feia") {
            std::cout << "O jardineiro usou a " << getNome() << " e cortou uma planta feia (" << p->getNome() << ")" << std::endl;
            c->removerPlanta();
        }
    }

    return true;
}

std::string Tesoura::getDesc() const {
    std::ostringstream str;
    str << getNome() << " (nr de serie: " << getNumSerie() << ")";
    return str.str();
}

Enxada::Enxada() : Ferramenta('z', "Enxada"), usos(0) {}

Enxada * Enxada::copia() const {
    return new Enxada(*this);
}

bool Enxada::usar(Celula* c) {
    if (c != nullptr && c->temPlanta()) {
        usos++;

        std::cout << "O jardineiro usou a " << getNome() << " e ao cavar arrancou um(a) " << c->getPlanta()->getNome() << std::endl;
        c->retirarAgua(Settings::Enxada::perda_agua);
        c->adicionarNutrientes(Settings::Enxada::aumenta_nutrientes);
        c->removerPlanta();

        if (usos >= Settings::Enxada::max_usos) {
            std::cout << "A enxada partiu-se" << std::endl;
            return false;
        }
    }

    return true;
}

std::string Enxada::getDesc() const {
    std::ostringstream str;
    str << getNome() << " (nr de serie: " << getNumSerie() << ") usada " << usos << " vezes";
    return str.str();
}
