#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>

using namespace std;

class Planta {
  private:
    string beleza;
    string nome;
    char simbolo;
    int nutrientes;
    int agua;

  protected:
    Planta(string n, string b, char s, int nut, int a);

  public:
    virtual Planta * copia() const = 0;
    char getSimbolo() const;
    string getPropriedades() const;
};

class Roseira : public Planta {
    public:
        Roseira();
        Roseira * copia() const override;
};

class ErvaDaninha: public Planta {
    public:
        ErvaDaninha();
        ErvaDaninha * copia() const override;
};

class Exotica : public Planta {
    public:
        Exotica();
        Exotica * copia() const override;
};

class Cacto : public Planta {
    public:
        Cacto();
        Cacto * copia() const override;
};

#endif
