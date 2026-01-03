#ifndef COMANDO_H
#define COMANDO_H

#include <iostream>
#include "../Jardim/Jardim.h"

using namespace std;

class Comando {
  public:
    virtual ~Comando() {}
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

class larea : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class lsolo : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class lferr : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class colhe : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class larga : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class pega : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class compra : public Comando {
  public:
    bool executar(Jardim *jardim, string *argv, int argc) override;
};

class mover : public Comando {
  char direcao;
    
  public:
    mover(char d);
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class entra : public Comando {
  public:
    bool executar(Jardim * jardim, string * argv, int argc) override;
};

class sai : public Comando {
  public:
  bool executar(Jardim * jardim, string * argv, int argc) override;
};

class grava : public Comando {
  public:
    bool executar(Jardim *jardim, string *argv, int argc) override;
};

class recupera : public Comando {
  public:
    bool executar(Jardim *jardim, string *argv, int argc) override;
};

class apaga : public Comando {
public:
  bool executar(Jardim *jardim, string *argv, int argc) override;
};

class executa : public Comando {
  public:
    bool executar(Jardim *jardim, string *argv, int argc) override;
};

#endif
