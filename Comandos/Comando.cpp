#include "Comando.h"

bool lplantas::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool lplanta::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 2) {
        cout << "Uso: lplanta <linha> <coluna>" << endl;
        return false;
    }

    int linha = stoi(argv[0]);
    int coluna = stoi(argv[1]);

    if(linha > jardim->getNLinhas() || coluna > jardim->getNColunas() || linha < 0 || coluna < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    cout << "Comando não implementado" << endl;
    return true;
}

bool planta::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr && argc != 3)
        return false;

    int linha = stoi(argv[0]);
    int coluna = stoi(argv[1]);

    jardim->criarPlanta(coluna, linha, argv[2]);

    return true;
}

bool avanca::executar(Jardim *jardim, string *argv, int argc) {
    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }

    int n = 1;
    if (argc > 0) {
        n = stoi(argv[0]);
        if(n < 0) {
            cout << "[n] tem de ser numero positivo" << endl;
            return false;
        }
    }

    cout << "avanca [" << n << "]" << endl;
    cout << "Comando nao implementado" << endl;
    return true;
}

