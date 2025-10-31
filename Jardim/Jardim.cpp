#include <iostream>
#include "Ferramenta.h"
#include "Jardim.h"

Jardim::Jardim(int l, int c) : nLinhas(l), nColunas(c) {
    grelha = new Celula*[nLinhas];
    for (int i = 0; i < nLinhas; i++) {
        grelha[i] = new Celula[nColunas];
    }

    int ferrColocadas = 0;
    int tentativas = 0;
    do {
        int randLinha = Random::getRandom(nLinhas-1);
        int randColuna = Random::getRandom(nColunas-1);

        if (!grelha[randLinha][randColuna].temFerramenta()) {
            Ferramenta * ferramenta = nullptr;
            int tipo = Random::getRandom(1, 4);

            if (tipo == 1)
                ferramenta = new Regador();
            else if (tipo == 2)
                ferramenta = new Adubo();
            else if (tipo == 3)
                ferramenta = new Tesoura();
            else if (tipo == 4)
                ferramenta = new Enxada();

            grelha[randLinha][randColuna].setFerramenta(ferramenta);
            ferrColocadas++;
        }

        tentativas++;
    } while (ferrColocadas < 3 && tentativas < 100);

    cout << "Jardim criado" << endl;
}

Jardim::~Jardim() {
  if (grelha != nullptr) {
    for (int i = 0; i < nLinhas; i++) {
      delete[] grelha[i];
    }
    delete[] grelha;
  }
}

int Jardim::getNColunas() const {
    return nColunas;
}

int Jardim::getNLinhas() const {
    return nLinhas;
}

void Jardim::mostraGrelha() const {
    int a = (int) 'A';

    cout << " ";
    for (int i = 0; i < nLinhas+1; i++) {
            for (int j = 0; j < nColunas+1; j++) {
            if (i == 0 && j < nColunas)
                cout << (char) (a + j); // Escreve ABCD... na primeira linha

            if (i > 0) {
                if (j == 0 && j < nColunas)
                    cout << (char) (a + (i-1)); // Vai escrevendo ABC... pelas linhas
                else {
                    if (grelha[i-1][j-1].temPlanta())
                        cout << "p";
                    else if (grelha[i-1][j-1].temFerramenta())
                        cout << "f";
                    else
                        cout << " ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Jardim::criarPlanta(int c, int l, string tipo) {
    if (l < 1 || l >= nLinhas || c < 1 || c >= nColunas) {
        cout << "Parametros fora do limite do jardim";
        return;
    }

    if (!(tipo == "c" || tipo == "r" || tipo == "e" || tipo == "x")) {
        cout << "Tipo de planta invalido";
        return;
    }

    if (grelha[l-1][c-1].temPlanta()) return; // evitar por planta quando já há uma planta

    Planta * p = nullptr;
    if (tipo == "r") p = new Roseira();
    else if (tipo == "e") p = new ErvaDaninha();
    else if (tipo == "x") p = new Exotica();
    else if (tipo == "c") p = new Cacto();

    grelha[l-1][c-1].setPlanta(p);
}