#include "Celula.h"
#include "../Settings.h"

Celula::Celula() : planta(nullptr), ferramenta(nullptr) {
  agua = Random::getRandom(Settings::Jardim::agua_min, Settings::Jardim::agua_max);
  nutrientes = Random::getRandom(Settings::Jardim::nutrientes_min, Settings::Jardim::nutrientes_max);
}

Celula::~Celula() {}

void Celula::setPlanta(Planta * planta) {
  this->planta = planta;
}

bool Celula::temPlanta() const {
  return planta != nullptr;
}

bool Celula::removerPlanta() {
  if (planta != nullptr) {
    delete planta;
    planta = nullptr;
    return true;
  }

  return false;
}

Planta * Celula::getPlanta() const {
  return planta;
}

void Celula::removePlanta() {
  delete planta;
  planta = nullptr;
}

bool Celula::temFerramenta() const {
  return ferramenta != nullptr;
}

void Celula::setFerramenta(Ferramenta* ferramenta) {
  this->ferramenta = ferramenta;
}

Ferramenta * Celula::getFerramenta() const {
  return ferramenta;
}

int Celula::getNutrientes() const {
  return nutrientes;
}

int Celula::getAgua() const {
  return agua;
}