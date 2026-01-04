#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>

using namespace std;

class Celula;

class Planta {
  public:
    virtual Planta * copia() const = 0;
    virtual ~Planta() = default;
    virtual bool processaInstante(Celula & c) = 0;
    char getSimbolo() const;
    string getBeleza() const;
    string getPropriedades() const;
    string getNome() const;
    bool getInvasora() const;
    virtual bool podeMultiplicar() const = 0;
    virtual Planta* multiplica() = 0;
    virtual void reageMorte(Celula & c);
    virtual bool podeMorrerSufocada();
    
  protected:
    Planta(const string & n, const string & b, char s, int nut, int a, bool i);
    void setAgua(int a);
    void setNutrientes(int n);
    int getAgua() const;
    int getNutrientes() const;

  private:
    string beleza;
    string nome;
    char simbolo;
    int nutrientes;
    int invasora;
    int agua;
};

class Roseira : public Planta {
  public:
    Roseira();
    Roseira * copia() const override;
    Planta * multiplica() override;
    bool processaInstante(Celula & c) override;
    bool podeMultiplicar() const override;
    bool podeMorrerSufocada() override;
    void reageMorte(Celula & c) override;
};

class ErvaDaninha: public Planta {
  public:
    ErvaDaninha();
    ErvaDaninha * copia() const override;
    Planta * multiplica() override;
    bool processaInstante(Celula & c) override;
    bool podeMultiplicar() const override;

  private:
    int instantesMorte;
    int instantesMultiplicacao;
};

class Bananeira : public Planta {
  public:
    Bananeira();
    Bananeira * copia() const override;
    Planta * multiplica() override;
    bool processaInstante(Celula & c) override;
    bool podeMultiplicar() const override;
    void reageMorte(Celula & c);
};

class Cacto : public Planta {
  public:
    Cacto();
    Cacto * copia() const override;
    Planta * multiplica() override;
    bool processaInstante(Celula & c) override;
    bool podeMultiplicar() const override;
    void reageMorte(Celula & c);
  
  private:
    int instantesAguaSolo;
    int instantesNutSolo;
};

#endif
