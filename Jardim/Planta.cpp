#include "Planta.h"
#include <sstream>
#include "../Settings.h"
#include "Celula.h"

Planta::Planta(const string & n, const string & b, char s, int nut, int a, bool i) : nome(n), beleza(b), simbolo(s), nutrientes(nut), agua(a), invasora(i) {}

char Planta::getSimbolo() const {
    return simbolo;
}

string Planta::getPropriedades() const {
    ostringstream str;

    str << nome << " ("<< beleza << ") com " << nutrientes << " de nutrientes e " << agua << " de agua";
    return str.str();
}

string Planta::getNome() const {
    return nome;
}

bool Planta::getInvasora() const {
    return invasora;
}

void Planta::setAgua(int a) {
    agua = a;

    if (agua < 0) agua = 0;
}

void Planta::setNutrientes(int n) {
    nutrientes = n;

    if (nutrientes < 0) nutrientes = 0;
}

int Planta::getAgua() const {
    return agua;
}

int Planta::getNutrientes() const {
    return nutrientes;
}

Roseira::Roseira() : Planta("Roseira", "bonita", 'r', Settings::Roseira::inicial_nutrientes, Settings::Roseira::inicial_agua, false) {}

Roseira * Roseira::copia() const { return new Roseira(*this); }

bool Roseira::podeMultiplicar() const {
    return getNutrientes() > Settings::Roseira::multiplica_nutrientes_maior;
}

bool Roseira::processaInstante(Celula & c) {

}

ErvaDaninha::ErvaDaninha() : Planta("Erva Daninha", "feia", 'e', Settings::ErvaDaninha::inicial_nutrientes, Settings::ErvaDaninha::inicial_agua, true) {
    instantesMultiplicacao = 0;
    instantesMorte = 0;
}

ErvaDaninha * ErvaDaninha::copia() const { return new ErvaDaninha(*this); }

bool ErvaDaninha::podeMultiplicar() const {
    return getNutrientes() > Settings::ErvaDaninha::multiplica_nutrientes_maior && instantesMultiplicacao > Settings::ErvaDaninha::multiplica_instantes;
}

bool ErvaDaninha::processaInstante(Celula & c) {
    
}

Exotica::Exotica() : Planta("Exotica", "divinal", 'x', 0, 0, true) {}

Exotica * Exotica::copia() const { return new Exotica(*this); }

bool Exotica::processaInstante(Celula & c) {
    
}

Cacto::Cacto() : Planta("Cacto", "neutra", 'c', 0, 0, false) {
    instantesAguaSolo = 0;
    instantesNutSolo = 0;
}

Cacto * Cacto::copia() const { return new Cacto(*this); }

bool Cacto::podeMultiplicar() const {
    return getNutrientes() > Settings::Cacto::multiplica_nutrientes_maior && getAgua() > Settings::Cacto::multiplica_agua_maior;
}

Planta * Cacto::multiplica() {

}

bool Cacto::processaInstante(Celula & c) {
    int aguaAbsorvida = c.getAgua() * Settings::Cacto::absorcao_agua_percentagem;
    c.retirarAgua(aguaAbsorvida);
    setAgua(getAgua() + aguaAbsorvida);

    int nutrientesSolo = c.getNutrientes();
    int nutAbsorvidos = (nutrientesSolo >= Settings::Cacto::absorcao_nutrientes) ? Settings::Cacto::absorcao_nutrientes : nutrientesSolo;
    c.retirarNutrientes(nutAbsorvidos);
    setNutrientes(getNutrientes() + nutAbsorvidos);

    if (c.getAgua() > Settings::Cacto::morre_agua_solo_maior) ++instantesAguaSolo;
    else instantesAguaSolo = 0;

    if (c.getNutrientes() < Settings::Cacto::morre_nutrientes_solo_menor) ++instantesNutSolo;
    else instantesNutSolo = 0;

    bool morreuPorAgua = instantesAguaSolo == Settings::Cacto::morre_agua_solo_instantes;
    bool morreuPorNutrientes = instantesNutSolo == Settings::Cacto::morre_nutrientes_solo_instantes;
    bool morreu = morreuPorAgua || morreuPorNutrientes;

    if (morreu) {
        c.adicionarNutrientes(this->getNutrientes());
        return false; // como morreu retorna false
    }

    return true;
}