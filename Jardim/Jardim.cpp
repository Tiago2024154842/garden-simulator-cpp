#include "Jardim.h"
#include <sstream>

Jardim::Jardim(int l, int c) : nLinhas(l), nColunas(c), instante(0), jardLinha(-1), jardColuna(-1) {
    jardineiro = new Jardineiro();
    grelha = new Celula*[nLinhas];
    for (int i = 0; i < nLinhas; ++i) {
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
            ++ferrColocadas;
        }

        ++tentativas;
    } while (ferrColocadas < 3 && tentativas < 100);

    cout << "Jardim criado" << endl;
}

Jardim::Jardim(const Jardim & outro) {
    nColunas = outro.nColunas;
    nLinhas = outro.nLinhas;
    jardLinha = outro.jardLinha;
    jardColuna = outro.jardColuna;
    
    
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

bool Jardim::verificaLimites(int l, int c) const {
    if (l < 0 || l >= nLinhas || c < 0 || c >= nColunas) {
        cout << "Erro: Fora do limite do jardim" << endl;
        return false;
    }

    return true;
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
                    Celula celula = grelha[i-1][j-1];

                    if (i-1 == jardLinha && j-1 == jardColuna)
                        cout << '*';
                    else if (celula.temPlanta())
                        cout << celula.getPlanta()->getSimbolo();
                    else if (celula.temFerramenta())
                        cout << celula.getFerramenta()->getSimbolo();
                    else
                        cout << ' ';
                }
            }
        }
        cout << endl;
    }
}

bool Jardim::criarPlanta(int l, int c, char tipo) {
    if (!verificaLimites(l, c)) return false;

    tipo = tolower(tipo);

    if (!(tipo == 'c' || tipo == 'r' || tipo == 'e' || tipo == 'x')) {
        cout << "Erro: Tipo de planta invalido" << endl;
        return false;
    }

    if (grelha[l][c].temPlanta()) {
        cout << "Erro: Ja existe uma planta nessa posicao" << endl;
        return false;
    }

    Planta * p = nullptr;
    if (tipo == 'r') p = new Roseira();
    else if (tipo == 'e') p = new ErvaDaninha();
    else if (tipo == 'x') p = new Exotica();
    else if (tipo == 'c') p = new Cacto();
    else return false;

    grelha[l][c].setPlanta(p);
    return true;
}

bool Jardim::removerPlanta(int l, int c) {
    if (!verificaLimites(l, c)) return false;

    if (!grelha[l][c].temPlanta()) {
        cout << "Erro: Nao existe uma planta nessa posicao" << endl;
        return false;
    }

    return grelha[l][c].removerPlanta();
}

bool Jardim::getDescPlanta(int l, int c) const {
    if (!verificaLimites(l, c)) return false;

    if (!grelha[l][c].temPlanta()) {
        cout << "Erro: Nao existe nenhuma planta nessa posicao" << endl;
        return false;
    }

    Planta * p = grelha[l][c].getPlanta();
    cout << p->getPropriedades() << endl;
    return true;
}

bool Jardim::moverJardineiro(char direcao) {
    int linha = jardLinha;
    int coluna = jardColuna;

    if (direcao == 'e')
        --coluna;
    else if (direcao == 'd')
        ++coluna;
    else if (direcao == 'c')
        --linha;
    else
        ++linha;

    return Jardim::setJardineiro(linha, coluna);
}

bool Jardim::setJardineiro(int l, int c) {
    if (!verificaLimites(l, c)) return false;

    if (jardLinha == l && jardColuna == c) {
        cout << "Erro: O jardineiro ja estava nessa posicao" << endl;
        return false;
    }

    jardLinha = l;
    jardColuna = c;
    return true;
} 

bool Jardim::sairJardineiro() {
    if (jardLinha == -1 || jardColuna == -1) {
        cout << "Erro: O jardineiro já estava fora do jardim" << endl; 
        return false;
    }

    jardLinha = -1;
    jardColuna = -1;
    return true;
}

bool Jardim::compraFerramenta(char f) {   
    Ferramenta * ferr;
    if (f == 'g') ferr = new Regador();
    else if (f == 't') ferr = new Tesoura();
    else if (f == 'a') ferr = new Adubo();
    else if (f == 'z') ferr = new Enxada();
    else {
        cout << "Erro: Ferramenta desconhecida no mercado online";
        return false;
    }

    cout << "Ferramenta comprada com sucesso" << endl;
    jardineiro->setFerramenta(ferr);
    return true;
}

void Jardim::listaFerramentas() const {
    cout << jardineiro->getFerramentas();
}

void Jardim::pegaFerramenta(int num) const {
    jardineiro->pegaFerramenta(num);
}

void Jardim::largaFerramenta() const {
    jardineiro->largaFerramenta();
}

void Jardim::listarPlantas() const {
    int nPlantas = 0;
    ostringstream str;

    str << "############# PLANTAS NO JARDIM #############" << endl;

    for (int l = 0; l < nLinhas; l++) {
        for (int c = 0; c < nColunas; c++) {
            if (grelha[l][c].temPlanta()) {
                ++nPlantas;
                Planta* p = grelha[l][c].getPlanta();
                char coordL = 'A' + l;
                char coordC = 'A' + c;

                str << "---------------- POSICAO " << coordL << coordC << " -----------------" << endl;
                str << p->getPropriedades() << endl;
                str << "Solo com " << grelha[l][c].getNutrientes() << " de nutrientes e " << grelha[l][c].getAgua() << " de agua" << endl;   
            }
        }
    }

    if  (nPlantas > 0)
        cout << str.str();
    else 
        cout << "Aviso: Nao ha nenhuma planta no jardim" << endl;
}

void Jardim::listaArea() const {
    cout << "############# CONTEUDO DO JARDIM #############" << endl;

    for (int l = 0; l < nLinhas; l++) {
        for (int c = 0; c < nColunas; c++) {
            bool temInfo = grelha[l][c].temPlanta() || grelha[l][c].temFerramenta() || (jardLinha == l && jardColuna == c);

            if (temInfo)
                getCelulaDesc(l, c);
        }    
    }
}

void Jardim::listaSolo(int l, int c, int n) const {
    if (n == 0) {
        getCelulaDesc(l, c);
    } else {
        cout << "############ PROPRIEDADES DA AREA ############" << endl;
        int inicioL = (l - n < 0) ? 0 : l - n;
        int inicioC = (c - n < 0) ? 0 : c - n;
        int fimL = (l + n >= nLinhas) ? nLinhas - 1 : l + n;
        int fimC = (c + n >= nColunas) ? nColunas - 1 : c + n;

        for (int i = inicioL; i <= fimL; ++i) {
            for (int j = inicioC; j <= fimC; ++j)
                getCelulaDesc(i, j);
        }
    }
}

void Jardim::getCelulaDesc(int l, int c) const {
    char coordL = 'A' + l;
    char coordC = 'A' + c;

    cout << "----------------- POSICAO " << coordL << coordC << " -----------------" << endl;
    cout << "Solo com " << grelha[l][c].getNutrientes() << " de nutrientes e " << grelha[l][c].getAgua() << " de agua" << endl;

    bool temPlanta = grelha[l][c].temPlanta();
    bool temFerramenta = grelha[l][c].temFerramenta();
    bool temJardineiro = (jardLinha == l && jardColuna == c);

    if (temPlanta) {
        Planta* p = grelha[l][c].getPlanta();

        cout << p->getPropriedades() << endl;
    }

    if (temFerramenta) {
        Ferramenta * f = grelha[l][c].getFerramenta();

        cout << f->getDesc() << endl;
    }

    if (temJardineiro) 
        cout << "Jardineiro" << endl;
}