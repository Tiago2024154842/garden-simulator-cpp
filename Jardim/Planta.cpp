#include "Planta.h"
#include <sstream>
#include "../Settings.h"

Planta::Planta(const string & n, const string & b, char s, int nut, int a) : nome(n), beleza(b), simbolo(s), nutrientes(nut), agua(a) {}

char Planta::getSimbolo() const {
    return simbolo;
}

string Planta::getPropriedades() const {
    ostringstream str;

    str << nome << " ("<< beleza << ") com " << nutrientes << " de nutrientes e " << agua << " de agua";
    return str.str();
}

Roseira::Roseira() : Planta("Roseira", "bonita", 'r', Settings::Roseira::inicial_nutrientes, Settings::Roseira::inicial_agua) {}

Roseira * Roseira::copia() const { return new Roseira(*this); }

ErvaDaninha::ErvaDaninha() : Planta("Erva Daninha", "feia", 'e', Settings::ErvaDaninha::inicial_nutrientes, Settings::ErvaDaninha::inicial_agua) {}

ErvaDaninha * ErvaDaninha::copia() const { return new ErvaDaninha(*this); }

Exotica::Exotica() : Planta("Exotica", "divinal", 'x', 10, 10) {}

Exotica * Exotica::copia() const { return new Exotica(*this); }

Cacto::Cacto() :  Planta("Cacto", "neutra", 'c', 10, 10) {}

Cacto * Cacto::copia() const { return new Cacto(*this); }