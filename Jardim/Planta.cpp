#include "Planta.h"
#include <sstream>
#include "../Settings.h"

Roseira::Roseira() {
    beleza = "bonita";
    nutrientes = Settings::Roseira::inicial_nutrientes;
    agua = Settings::Roseira::inicial_agua;
}

string Roseira::getPropriedades() const {
    ostringstream str;

    str << "Roseira ("<< beleza << ") com " << nutrientes << "% de nutrientes e " << agua << "% de agua";
    return str.str();
}

ErvaDaninha::ErvaDaninha() {
    beleza = "feia";
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
    agua = Settings::ErvaDaninha::inicial_agua;
}

string ErvaDaninha::getPropriedades() const {
    ostringstream str;

    str << "Erva Daninha ("<< beleza << ") com " << nutrientes << "% de nutrientes e " << agua << "% de agua";
    return str.str();
}

Exotica::Exotica() {}

string Exotica::getPropriedades() const {
    ostringstream str;

    str << "Planta exotica ("<< beleza << ") com " << nutrientes << "% de nutrientes e " << agua << "% de agua";
    return str.str();
}

Cacto::Cacto() {
    beleza = "neutra";
}

string Cacto::getPropriedades() const {
    ostringstream str;

    str << "Cacto com ("<< beleza << ") com " << nutrientes << "% de nutrientes e " << agua << "% de agua";
    return str.str();
}

