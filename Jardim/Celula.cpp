#include "Celula.h"

Celula::Celula() : planta(nullptr), ferramenta(nullptr), jardineiro(nullptr) {
  agua = Random::getRandom(80, 100);
  nutrientes = Random::getRandom(40, 50);
}

Celula::~Celula() {}

void Celula::setPlanta(Planta * planta) {
  this->planta = planta;
}

bool Celula::temPlanta() const {
  return planta != nullptr;
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

void Celula::setJardineiro(Jardineiro* jardineiro) {
  this->jardineiro = jardineiro;
}

Jardineiro * Celula::getJardineiro() const {
  return jardineiro;
}

bool Celula::temJardineiro() const {
  return jardineiro != nullptr;
}