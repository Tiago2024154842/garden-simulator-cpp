#ifndef CELULA_H
#define CELULA_H

#include <iostream>
#include "Random/Random.h"
#include "Planta.h"
#include "Ferramenta.h"
#include "Jardineiro.h"

using namespace std;

class Celula {
  private:
    Planta* planta;
    Ferramenta* ferramenta;
    Jardineiro* jardineiro;
    int nutrientes;
    int agua;

  public:
    Celula();
    ~Celula();
    void setPlanta(Planta* planta);
    bool temPlanta() const;
    Planta * getPlanta() const;
    void removePlanta();
    void setFerramenta(Ferramenta* ferramenta);
    bool temFerramenta() const;
    Jardineiro * getJardineiro() const;
    void setJardineiro(Jardineiro* jardineiro);
    bool temJardineiro() const;
};

#endif
