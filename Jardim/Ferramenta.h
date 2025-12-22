#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>

class Ferramenta {
    static int numSerie;

  public:
    virtual void usar() const = 0;
};

class Regador : public Ferramenta {
    void usar() const override;
};

class Adubo : public Ferramenta {
    void usar() const override;
};

class Tesoura : public Ferramenta {
    void usar() const override;
};

class Enxada : public Ferramenta {
    void usar() const override;
};

#endif
