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
    char getSimbolo() const;
    string getPropriedades() const;
};

class Roseira : public Planta {
    public:
        Roseira();
};

class ErvaDaninha: public Planta {
    public:
        ErvaDaninha();
};

class Exotica : public Planta {
    public:
        Exotica();
};

class Cacto : public Planta {
    public:
        Cacto();
};

#endif
