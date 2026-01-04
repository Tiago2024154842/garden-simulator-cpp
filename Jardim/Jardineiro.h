#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include <vector>
#include "Ferramenta.h"

class Jardineiro {
  public:
    Jardineiro();
    Jardineiro(const Jardineiro & outro);
    ~Jardineiro();
    void setFerramenta(Ferramenta * f);
    std::string getFerramentas() const;
    void pegaFerramenta(int num);
    void largaFerramenta();
    int getLinha() const;
    int getColuna() const;
    bool podeMover() const;
    bool podeColher() const;
    bool podePlantar() const;
    bool podeEntrar() const;
    bool podeSair() const;
    bool estaNoJardim() const;
    bool estaNaPosicao(int l, int c) const;
    void setPosicao(int l, int c);
    void resetContadoresTurno();
    void registarMovimento();
    void registarPlantacao();
    void registarColheita();
    void registarEntrada();
    void sairDoJardim();
    void usarFerramenta(Celula * area);

  private:
    int movimentosTurno;
    int colheitasTurno;
    int plantacoesTurno;
    int saidasTurno;
    int entradasTurno;
    int linha;
    int coluna;
    bool noJardim;
    Ferramenta * mao;
    std::vector<Ferramenta*> inventario;
};

#endif
