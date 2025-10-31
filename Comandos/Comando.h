#ifndef COMANDO_H
#define COMANDO_H

#include <iostream>
#include "../Jardim/Jardim.h"

using namespace std;

class Comando {
  public:
    virtual bool executar(Jardim * jardim, string * argv, int argc) = 0;
};

class lplantas : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class lplanta : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class jardim : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class planta : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class avanca : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};


#endif
