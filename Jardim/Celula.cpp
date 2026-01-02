#include "Celula.h"
#include "../Settings.h"

Celula::Celula() : planta(nullptr), ferramenta(nullptr) {
  agua = Random::getRandom(Settings::Jardim::agua_min, Settings::Jardim::agua_max);
  nutrientes = Random::getRandom(Settings::Jardim::nutrientes_min, Settings::Jardim::nutrientes_max);
}

Celula::~Celula() {
  removerPlanta();

  if (ferramenta != nullptr) {
    delete ferramenta;
    ferramenta = nullptr;
  }
}

void Celula::setPlanta(Planta * planta) {
  if (this->planta == nullptr)
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

bool Celula::temFerramenta() const {
  return ferramenta != nullptr;
}

void Celula::setFerramenta(Ferramenta* ferramenta) {
  if (this->ferramenta == nullptr)
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

void Celula::setAgua(int a) {
  if (a < 0) a = 0;
  agua = a;
}

void Celula::setNutrientes(int n) {
  if (n < 0) n = 0;
  nutrientes = n;
}