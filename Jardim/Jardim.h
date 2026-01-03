#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>
#include "../Random/Random.h"
#include "Celula.h"
#include "Jardineiro.h"
#include "Ferramenta.h"
 
class Jardim {
  public:
    Jardim(int c, int l);
    Jardim(const Jardim & outro);
    Jardim & operator=(Jardim outro);
    ~Jardim();
    void mostraGrelha() const;
    int getNColunas() const;
    int getNLinhas() const;
    bool getDescPlanta(int l, int c) const;
    bool plantarPlanta(int l, int c, char tipo);
    bool removerPlanta(int l, int c);
    bool moverJardineiro(char c);
    bool sairJardineiro();
    bool entrarJardineiro(int l, int c);
    bool compraFerramenta(char f);
    void listaFerramentas() const;
    void pegaFerramenta(int num) const;
    void largaFerramenta() const;
    void listarPlantas() const;
    void listaArea() const;
    void listaSolo(int l, int c, int n = 0) const;
    void avancaInstante();
    
  private:
    void swap(Jardim & outro);
    void getCelulaDesc(int l, int c) const;
    bool setJardineiro(int l, int c);
    bool verificaLimites(int l, int c) const;
    void verificarFerramentasNoChao(int l, int c);
    void criarNovaFerramenta(int l, int c);
    int instante;
    int nColunas;
    int nLinhas;
    Jardineiro * jardineiro;
    Celula ** grelha;
};

#endif
