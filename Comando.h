#ifndef COMANDO_H
#define COMANDO_H
#include <iostream>
#include <ostream>

class Comando {
    public:
    virtual bool executar() = 0;
};

class Lplantas : public Comando {
    public:
    bool executar() override;
};

class Jardim : public Comando {
    public:
    bool executar() override;
};

#endif
