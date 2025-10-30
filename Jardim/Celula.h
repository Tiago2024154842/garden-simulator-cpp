#ifndef CELULA_H
#define CELULA_H

#include <iostream>
#include "Planta.h"
#include "Ferramenta.h"

using namespace std;

class Celula {
  private:
    Planta* planta;
    Ferramenta* ferramenta;

  public:
    Celula();
    ~Celula();
    void setPlanta(Planta* planta);
    bool temPlanta() const;
    Planta * getPlanta() const;
    void removePlanta();
};

#endif
