#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>

class Celula;

class Ferramenta {
  public:
    std::string getNome() const;
    char getSimbolo() const;
    int getNumSerie() const;
    virtual Ferramenta * copia() const = 0;
    virtual void usar(Celula* area) = 0;
    virtual std::string getDesc() const = 0;

  protected:
    Ferramenta(char s, const std::string & n);

  private: 
    std::string nome;
    char simbolo;
    int numSerie;
    static int contadorNumSerie;
};

class Regador : public Ferramenta {
  public:
    Regador();
    Regador * copia() const override;
    void usar(Celula* area) override;
    std::string getDesc() const;
    
  private:
    int agua;
};

class Adubo : public Ferramenta {
  public:
    Adubo();
    Adubo * copia() const override;
    void usar(Celula* area) override;
    std::string getDesc() const override;

  private:
    int quantidade;
};

class Tesoura : public Ferramenta {
  public:
    Tesoura();
    Tesoura * copia() const override;
    void usar(Celula* area) override;
    std::string getDesc() const;
};

class Enxada : public Ferramenta {
  public:
    Enxada();
    Enxada * copia() const override;
    void usar(Celula* area) override;
    std::string getDesc() const;
};

#endif
