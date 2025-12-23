#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>
#include "../Random/Random.h"
#include "Celula.h"

using namespace std;

class Jardim {
  public:
    Jardim(int c, int l);
    ~Jardim();
    void mostraGrelha() const;
    int getNColunas() const;
    int getNLinhas() const;
    bool getDescPlanta(int l, int c) const;
    bool criarPlanta(int l, int c, char tipo);
    bool colocarJardineiro(int l, int c);

  private:
    bool verificaLimites(int l, int c) const;
    int instante;
    int nColunas;
    int nLinhas;
    Celula * jardineiroPos;
    Celula ** grelha;
};

#endif
