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

    std::cout << "Jardim criado" << std::endl;
}

Jardim::Jardim(const Jardim & outro) {
    nColunas = outro.nColunas;
    nLinhas = outro.nLinhas;
    jardLinha = outro.jardLinha;
    jardColuna = outro.jardColuna;
    
    if (outro.jardineiro != nullptr)
        jardineiro = new Jardineiro(*outro.jardineiro); // construtor por copia
    else
        jardineiro = nullptr;

    grelha = new Celula*[nLinhas];
    
    for (int l = 0; l < nLinhas; ++l) 
        grelha[l] = new Celula[nColunas];
    
    for (int l = 0; l < nLinhas; ++l) {
        for (int c = 0; c < nColunas; ++c) {
            grelha[l][c].setNutrientes(outro.grelha[l][c].getNutrientes());
            grelha[l][c].setAgua(outro.grelha[l][c].getAgua());

            if (outro.grelha[l][c].temPlanta()) 
                grelha[l][c].setPlanta(outro.grelha[l][c].getPlanta()->copia());
            
            if (outro.grelha[l][c].temFerramenta()) 
                grelha[l][c].setFerramenta(outro.grelha[l][c].getFerramenta()->copia());
        }
    }
}

Jardim & Jardim::operator=(Jardim outro) {
    swap(outro);
    return *this;
}

Jardim::~Jardim() {
    if (grelha != nullptr) {
        for (int i = 0; i < nLinhas; i++) {
        delete[] grelha[i];
        }
        delete[] grelha;
    }

    if (jardineiro != nullptr) {
        delete jardineiro;
    }
}

void Jardim::swap(Jardim & outro) {
    std::swap(nColunas, outro.nColunas);
    std::swap(nLinhas, outro.nLinhas);
    std::swap(jardLinha, outro.jardLinha);
    std::swap(jardColuna, outro.jardColuna);
    std::swap(instante, outro.instante);
    std::swap(grelha, outro.grelha); 
    std::swap(jardineiro, outro.jardineiro);
}

int Jardim::getNColunas() const {
    return nColunas;
}

int Jardim::getNLinhas() const {
    return nLinhas;
}

bool Jardim::verificaLimites(int l, int c) const {
    if (l < 0 || l >= nLinhas || c < 0 || c >= nColunas) {
        std::cout << "Erro: Fora do limite do jardim" << std::endl;
        return false;
    }

    return true;
}

void Jardim::mostraGrelha() const {
    int a = (int) 'A';

    std::cout << " ";
    for (int i = 0; i < nLinhas+1; i++) {
            for (int j = 0; j < nColunas+1; j++) {
            if (i == 0 && j < nColunas)
                std::cout << (char) (a + j); // Escreve ABCD... na primeira linha

            if (i > 0) {
                if (j == 0 && j < nColunas)
                    std::cout << (char) (a + (i-1)); // Vai escrevendo ABC... pelas linhas
                else {
                    const Celula & celula = grelha[i-1][j-1];

                    if (i-1 == jardLinha && j-1 == jardColuna)
                        std::cout << '*';
                    else if (celula.temPlanta())
                        std::cout << celula.getPlanta()->getSimbolo();
                    else if (celula.temFerramenta())
                        std::cout << celula.getFerramenta()->getSimbolo();
                    else
                        std::cout << ' ';
                }
            }
        }
        std::cout << std::endl;
    }
}

bool Jardim::criarPlanta(int l, int c, char tipo) {
    if (!verificaLimites(l, c)) return false;

    tipo = tolower(tipo);

    if (!(tipo == 'c' || tipo == 'r' || tipo == 'e' || tipo == 'x')) {
        std::cout << "Erro: Tipo de planta invalido" << std::endl;
        return false;
    }

    if (grelha[l][c].temPlanta()) {
        std::cout << "Erro: Ja existe uma planta nessa posicao" << std::endl;
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
        std::cout << "Erro: Nao existe uma planta nessa posicao" << std::endl;
        return false;
    }

    return grelha[l][c].removerPlanta();
}

bool Jardim::getDescPlanta(int l, int c) const {
    if (!verificaLimites(l, c)) return false;

    if (!grelha[l][c].temPlanta()) {
        std::cout << "Erro: Nao existe nenhuma planta nessa posicao" << std::endl;
        return false;
    }

    Planta * p = grelha[l][c].getPlanta();
    std::cout << p->getPropriedades() << std::endl;
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
        std::cout << "Erro: O jardineiro ja estava nessa posicao" << std::endl;
        return false;
    }

    jardLinha = l;
    jardColuna = c;
    return true;
} 

bool Jardim::sairJardineiro() {
    if (jardLinha == -1 || jardColuna == -1) {
        std::cout << "Erro: O jardineiro já estava fora do jardim" << std::endl; 
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
        std::cout << "Erro: Ferramenta desconhecida no mercado online";
        return false;
    }

    std::cout << "Ferramenta comprada com sucesso" << std::endl;
    jardineiro->setFerramenta(ferr);
    return true;
}

void Jardim::listaFerramentas() const {
    std::cout << jardineiro->getFerramentas();
}

void Jardim::pegaFerramenta(int num) const {
    jardineiro->pegaFerramenta(num);
}

void Jardim::largaFerramenta() const {
    jardineiro->largaFerramenta();
}

void Jardim::listarPlantas() const {
    int nPlantas = 0;
    std::ostringstream str;

    str << "############# PLANTAS NO JARDIM #############" << std::endl;

    for (int l = 0; l < nLinhas; l++) {
        for (int c = 0; c < nColunas; c++) {
            if (grelha[l][c].temPlanta()) {
                ++nPlantas;
                Planta* p = grelha[l][c].getPlanta();
                char coordL = 'A' + l;
                char coordC = 'A' + c;

                str << "---------------- POSICAO " << coordL << coordC << " -----------------" << std::endl;
                str << p->getPropriedades() << std::endl;
                str << "Solo com " << grelha[l][c].getNutrientes() << " de nutrientes e " << grelha[l][c].getAgua() << " de agua" << std::endl;   
            }
        }
    }

    if (nPlantas > 0)
        std::cout << str.str();
    else 
        std::cout << "Aviso: Nao ha nenhuma planta no jardim" << std::endl;
}

void Jardim::listaArea() const {
    std::cout << "############# CONTEUDO DO JARDIM #############" << std::endl;

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
        std::cout << "############ PROPRIEDADES DA AREA ############" << std::endl;
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

    std::cout << "----------------- POSICAO " << coordL << coordC << " -----------------" << std::endl;
    std::cout << "Solo com " << grelha[l][c].getNutrientes() << " de nutrientes e " << grelha[l][c].getAgua() << " de agua" << std::endl;

    bool temPlanta = grelha[l][c].temPlanta();
    bool temFerramenta = grelha[l][c].temFerramenta();
    bool temJardineiro = (jardLinha == l && jardColuna == c);

    if (temPlanta) {
        Planta* p = grelha[l][c].getPlanta();
        std::cout << p->getPropriedades() << std::endl;
    }

    if (temFerramenta) {
        Ferramenta * f = grelha[l][c].getFerramenta();
        std::cout << f->getDesc() << std::endl;
    }

    if (temJardineiro) 
        std::cout << "Jardineiro" << std::endl;
}