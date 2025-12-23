#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>

using namespace std;

class Planta {
    public:
        int nutrientes;
        int agua;
        string beleza;
        virtual string getPropriedades() const = 0;
};

class Roseira : public Planta {
    public:
        Roseira();
        string getPropriedades() const override;
};

class ErvaDaninha: public Planta {
    public:
        ErvaDaninha();
        string getPropriedades() const override;
};

class Exotica : public Planta {
    public:
        Exotica();
        string getPropriedades() const override;
};

class Cacto : public Planta {
    public:
        Cacto();
        string getPropriedades() const override;
};

#endif
