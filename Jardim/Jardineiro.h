#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include "Ferramenta.h"

class Jardineiro {
  public:
    Jardineiro();
    ~Jardineiro();
  private: 
    Ferramenta * mao;
    Ferramenta ** inventario;
};

#endif
