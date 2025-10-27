#include "Planta.h"
#include <iostream>
#include "../Settings.h"

Roseira::Roseira() {
    nutrientes = Settings::Roseira::inicial_nutrientes;
    agua = Settings::Roseira::inicial_agua;
}

ErvaDaninha::ErvaDaninha() {
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
    agua = Settings::ErvaDaninha::inicial_agua;
}

Exotica::Exotica() {}

Cacto::Cacto() {}