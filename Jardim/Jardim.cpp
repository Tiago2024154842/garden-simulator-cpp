#include <iostream>
#include "Jardim.h"

Jardim::Jardim(int l, int c) : nLinhas(l), nColunas(c) {
    grelha = new Celula*[nLinhas];
    for (int i = 0; i < nLinhas; i++) {
        grelha[i] = new Celula[nColunas];
    }
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
    if (l < 0 || l > nLinhas || c < 0 || c > nColunas) return;

    if (!(tipo == "c" || tipo == "r" || tipo == "e" || tipo == "x")) return;

    if (grelha[l-1][c-1].temPlanta()) return; // evitar por planta quando já há uma planta

    Planta * p = nullptr;
    if (tipo == "r") p = new Roseira();
    else if (tipo == "e") p = new ErvaDaninha();
    else if (tipo == "x") p = new Exotica();
    else if (tipo == "c") p = new Cacto();

    grelha[l-1][c-1].setPlanta(p);
}