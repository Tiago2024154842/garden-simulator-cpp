#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>
#include "../Random/Random.h"
#include "Celula.h"
#include "Jardineiro.h"
#include "Ferramenta.h"

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
    bool removerPlanta(int l, int c);
    bool moverJardineiro(char c);
    bool setJardineiro(int l, int c);
    bool compraFerramenta(char f);
    void listaFerramentas() const;
    void pegaFerramenta(int num) const;
    void largaFerramenta() const;
    

  private:
    bool verificaLimites(int l, int c) const;
    int instante;
    int nColunas;
    int nLinhas;
    int jardLinha;
    int jardColuna;
    Jardineiro * jardineiro;
    Celula ** grelha;
};

#endif
