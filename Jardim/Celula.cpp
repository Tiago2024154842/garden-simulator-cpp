#include "Celula.h"

Celula::Celula() : planta(nullptr), ferramenta(nullptr) {}
Celula::~Celula() {}

void Celula::setPlanta(Planta* planta) {
  cout << "Celula::setPlanta" << endl;
  this->planta = planta;
}

bool Celula::temPlanta() const {
  return planta != nullptr;
}

Planta* Celula::getPlanta() const {
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