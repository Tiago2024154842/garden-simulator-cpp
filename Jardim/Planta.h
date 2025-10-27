#ifndef PLANTA_H
#define PLANTA_H

class Planta {
    public:
        int nutrientes;
        int agua;
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
