#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>

class Celula;

class Ferramenta {
  public:
    char getSimbolo() const;
    int getNumSerie() const;
    virtual void usar(Celula* area) = 0;
    virtual std::string getDesc() const = 0;

  protected:
    Ferramenta(char s);

  private: 
    char simbolo;
    int numSerie;
    static int contadorNumSerie;
};

class Regador : public Ferramenta {
  public:
    Regador();
    void usar(Celula* area) override;
    std::string getDesc() const;
    
  private:
    int agua;
};

class Adubo : public Ferramenta {
  public:
    Adubo();
    void usar(Celula* area) override;
    std::string getDesc() const override;

  private:
    int quantidade;
};

class Tesoura : public Ferramenta {
  public:
    Tesoura();
    void usar(Celula* area) override;
    std::string getDesc() const;
};

class Enxada : public Ferramenta {
  public:
    Enxada();
    void usar(Celula* area) override;
    std::string getDesc() const;
};

#endif
