#ifndef JARDIM_H
#define JARDIM_H

#include "Celula.h"

using namespace std;

class Jardim {
  public:
    Jardim(int c, int l);
    ~Jardim();
    void mostraGrelha() const;
    int getNColunas() const;
    int getNLinhas() const;
    void criarPlanta(int c, int l, string tipo);

  private:
    int nColunas;
    int nLinhas;
    Celula ** grelha;
};

#endif
