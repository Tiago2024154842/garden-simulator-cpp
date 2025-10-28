#ifndef JARDIM_H
#define JARDIM_H

#include "Celula.h"

class Jardim {
  public:
    Jardim(int c, int l);

  private:
    int nColunas;
    int nLinhas;
    Celula ** grelha;
};

#endif
