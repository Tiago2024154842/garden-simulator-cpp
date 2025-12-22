#ifndef CELULA_H
#define CELULA_H

#include <iostream>
#include "Planta.h"
#include "Ferramenta.h"
#include "Jardineiro.h"

using namespace std;

class Celula {
  private:
    Planta* planta;
    Ferramenta* ferramenta;
    Jardineiro* jardineiro;

  public:
    Celula();
    ~Celula();
    void setPlanta(Planta* planta);
    bool temPlanta() const;
    Planta * getPlanta() const;
    void removePlanta();
    void setFerramenta(Ferramenta* ferramenta);
    bool temFerramenta() const;
};

#endif
