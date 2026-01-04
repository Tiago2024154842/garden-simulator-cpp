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

string Planta::getBeleza() const {
    return beleza;
}

bool Planta::podeMorrerSufocada() {
    return false;
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

void Planta::reageMorte(Celula & c) {}

Roseira::Roseira() : Planta("Roseira", "bonita", 'r', Settings::Roseira::inicial_nutrientes, Settings::Roseira::inicial_agua, false) {}

Roseira * Roseira::copia() const { return new Roseira(*this); }

bool Roseira::podeMultiplicar() const {
    return getNutrientes() > Settings::Roseira::multiplica_nutrientes_maior;
}

Planta * Roseira::multiplica() {
    Roseira* nova = new Roseira(); 

    setNutrientes(Settings::Roseira::original_nutrientes);
    nova->setNutrientes(Settings::Roseira::nova_nutrientes);

    int aguaNova = (getAgua() * Settings::Roseira::nova_agua_percentagem) / 100;
    nova->setAgua(aguaNova);

    int aguaAtual = (getAgua() * Settings::Roseira::original_agua_percentagem) / 100;
    setAgua(aguaAtual);

    return nova;
}

void Roseira::reageMorte(Celula & c) {
    c.adicionarAgua(getAgua() / 2);
    c.adicionarNutrientes(getNutrientes() / 2);
}

bool Roseira::processaInstante(Celula & c) {
    setAgua(getAgua() - Settings::Roseira::perda_agua);
    setNutrientes(getNutrientes() - Settings::Roseira::perda_nutrientes);

    int aguaAbsorvida = (c.getAgua() >= Settings::Roseira::absorcao_agua) ? Settings::Roseira::absorcao_agua : c.getAgua();
    c.retirarAgua(aguaAbsorvida);
    setAgua(getAgua() + aguaAbsorvida);

    int nutAbsorvidos = (c.getNutrientes() >= Settings::Roseira::absorcao_nutrientes) ? Settings::Roseira::absorcao_nutrientes : c.getNutrientes();
    c.retirarNutrientes(nutAbsorvidos);
    setNutrientes(getNutrientes() + nutAbsorvidos);

    bool morreuPorAgua = getAgua() < Settings::Roseira::morre_agua_menor;
    bool morreuPorNutrientes = getNutrientes() < Settings::Roseira::morre_nutrientes_menor;
    bool morreuDemasiadosNut = getNutrientes() > Settings::Roseira::morre_nutrientes_maior;
    bool morreu = morreuPorAgua || morreuPorNutrientes || morreuDemasiadosNut;

    if (morreu) 
        return false;

    return true;
}

bool Roseira::podeMorrerSufocada() {
    return true;
}

ErvaDaninha::ErvaDaninha() : Planta("Erva Daninha", "feia", 'e', Settings::ErvaDaninha::inicial_nutrientes, Settings::ErvaDaninha::inicial_agua, true) {
    instantesMultiplicacao = 0;
    instantesMorte = 0;
}

ErvaDaninha * ErvaDaninha::copia() const { return new ErvaDaninha(*this); }

bool ErvaDaninha::podeMultiplicar() const {
    return getNutrientes() > Settings::ErvaDaninha::multiplica_nutrientes_maior && instantesMultiplicacao > Settings::ErvaDaninha::multiplica_instantes;
}

Planta * ErvaDaninha::multiplica() {
    ErvaDaninha* nova = new ErvaDaninha();
    
    nova->setNutrientes(Settings::ErvaDaninha::nova_nutrientes);
    nova->setAgua(Settings::ErvaDaninha::nova_agua);
    instantesMultiplicacao = 0; 

    return nova;
}

bool ErvaDaninha::processaInstante(Celula & c) {
    instantesMorte++;
    instantesMultiplicacao++;

    if (instantesMorte >= Settings::ErvaDaninha::morre_instantes)
        return false;
    
    int aguaAbsorvida = (c.getAgua() >= Settings::ErvaDaninha::absorcao_agua) ? Settings::ErvaDaninha::absorcao_agua : c.getAgua();
    if (aguaAbsorvida > 0) {
        c.retirarAgua(aguaAbsorvida);
        setAgua(getAgua() + aguaAbsorvida);
    }

    int nutAbsorvidos = (c.getNutrientes() >= Settings::ErvaDaninha::absorcao_nutrientes) ? Settings::ErvaDaninha::absorcao_nutrientes : c.getNutrientes();
    if (nutAbsorvidos > 0) {
        c.retirarNutrientes(nutAbsorvidos);
        setNutrientes(getNutrientes() + nutAbsorvidos);
    }

    return true;
}

Bananeira::Bananeira() : Planta("Bananeira", "divinal", 'x', Settings::Bananeira::inicial_nutrientes, Settings::Bananeira::inicial_agua, false) {}

bool Bananeira::podeMultiplicar() const {
    return false;
}

Planta * Bananeira::multiplica() {
    return nullptr;
}

Bananeira * Bananeira::copia() const { return new Bananeira(*this); }

void Bananeira::reageMorte(Celula & c) {
    c.adicionarNutrientes(50);
    c.adicionarAgua(this->getAgua());
}

bool Bananeira::processaInstante(Celula & c) {
    setAgua(getAgua() - Settings::Bananeira::perda_agua);
    setNutrientes(getNutrientes() - Settings::Bananeira::perda_nutrientes);

    if (c.getAgua() > 0) {
        c.retirarAgua(Settings::Bananeira::absorcao_agua);
        setAgua(getAgua() + Settings::Bananeira::absorcao_agua);
    }
    
    if (c.getNutrientes() > 0) {
        c.retirarNutrientes(Settings::Bananeira::absorcao_nutrientes);
        setNutrientes(getNutrientes() + Settings::Bananeira::absorcao_nutrientes);
    }

    bool morreuPorAgua = getAgua() < Settings::Bananeira::morre_agua_menor;
    bool morreuPorNutrientes = getNutrientes() < Settings::Bananeira::morre_nutrientes_menor; 
    bool morreu = morreuPorAgua || morreuPorNutrientes;

    if (morreu)
        return false;

    return true;
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
    Cacto * nova = new Cacto();
    int metadeNut = getNutrientes() / 2;
    int metadeAgua = getAgua() / 2;

    setNutrientes(metadeNut);
    setAgua(metadeAgua);

    nova->setNutrientes(metadeNut);
    nova->setAgua(metadeAgua);

    return nova;
}

void Cacto::reageMorte(Celula & c) {
    c.adicionarNutrientes(this->getNutrientes());
}

bool Cacto::processaInstante(Celula & c) {
    int aguaAbsorvida = (c.getAgua() * Settings::Cacto::absorcao_agua_percentagem) / 100;
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

    bool morreuPorAgua = instantesAguaSolo >= Settings::Cacto::morre_agua_solo_instantes;
    bool morreuPorNutrientes = instantesNutSolo >= Settings::Cacto::morre_nutrientes_solo_instantes;
    bool morreu = morreuPorAgua || morreuPorNutrientes;

    if (morreu)
        return false;

    return true;
}