#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include <vector>
#include "Ferramenta.h"

class Jardineiro {
  public:
    Jardineiro();
    Jardineiro(const Jardineiro & outro);
    ~Jardineiro();
    void setFerramenta(Ferramenta * f);
    std::string getFerramentas() const;
    void pegaFerramenta(int num);
    void largaFerramenta();

  private: 
    Ferramenta * mao;
    std::vector<Ferramenta*> inventario;
};

#endif
