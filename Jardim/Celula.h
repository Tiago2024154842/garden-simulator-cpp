#ifndef CELULA_H
#define CELULA_H

#include <iostream>
#include "Random/Random.h"
#include "Planta.h"
#include "Ferramenta.h"

using namespace std;

class Celula {
  private:
    Planta* planta;
    Ferramenta* ferramenta;
    int nutrientes;
    int agua;

  public:
    Celula();
    ~Celula();
    int getNutrientes() const;
    int getAgua() const;
    void setAgua(int a);
    void setNutrientes(int n);
    void setPlanta(Planta* planta);
    bool removerPlanta();
    bool temPlanta() const;
    Planta * getPlanta() const;
    void removePlanta();
    void setFerramenta(Ferramenta* ferramenta);
    Ferramenta * getFerramenta() const;
    bool temFerramenta() const;
};

#endif
