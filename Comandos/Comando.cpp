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

    if (argc != 3) {
        cout << "Uso: planta <linha> <coluna> <Tipo>" << endl;
        return false;
    }

    int linha = stoi(argv[0]);
    int coluna = stoi(argv[1]);
    if(linha > jardim->getNLinhas() || coluna > jardim->getNColunas() || linha < 0 || coluna < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }
    if (!(argv[3] == "c" || argv[3] == "r" || argv[3] == "e" || argv[3] == "x")) {
        cout << "<Tipo> Errado. Pode meter entre [c] [r] [e] [x] "<< endl;
        return false;
    }

    cout << "Comando implementado nao na totalidade" << endl;
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

bool larea::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool lsolo::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    if (argc > 3 || argc < 2) {
        cout << "Uso: lsolo <linha> <coluna> [n]" << endl;
        return false;
    }

    int linha = stoi(argv[0]);
    int coluna = stoi(argv[1]);
    if(linha > jardim->getNLinhas() || coluna > jardim->getNColunas() || linha < 0 || coluna < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    if (argc == 3) {
        int n = stoi(argv[0]);
        if(n < 0) {
            cout << "[n] tem de ser numero positivo" << endl;
            return false;
        }

        cout << "Comando nao implementado com n" << endl;
        return true;
    }
    cout << "Comando nao implementado sem n" << endl;
    return true;
}

bool lferr::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool colhe::executar(Jardim * jardim, string* argv, int argc) {

    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 2) {
        cout << "Uso: colhe <linha> <coluna>" << endl;
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

bool larga::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool pega::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;
    if (argc != 1) {
        cout << "Uso: pega [n]" << endl;
        return false;
    }
    int n = stoi(argv[0]);
    if(n < 0) {
        cout << "[n] tem de ser numero positivo" << endl;
        return false;
    }
    cout << "Comando nao implementado" << endl;
    return true;
}

bool compra::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;
    if (argc != 1) {
        cout << "Uso: compra <c>" << endl;
        return false;
    }
    if (!(argv[1] == "g" || argv[1] == "a" || argv[1] == "t" || argv[1] == "z")) {
        cout << "<c> Errado. Pode meter entre [g] [a] [t] [z] "<< endl;
        return false;
    }

    cout << "Comando nao implementado" << endl;
    return true;
}

bool movEsquerda::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool movDireita::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool movCima::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool movBaixo::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool entra::executar(Jardim * jardim, string* argv, int argc) {

    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 2) {
        cout << "Uso: entra <linha> <coluna>" << endl;
        return false;
    }

    int linha = stoi(argv[0]);
    int coluna = stoi(argv[1]);
    if(linha > jardim->getNLinhas() || coluna > jardim->getNColunas() || linha < 0 || coluna < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    cout << "Comando nao implementado" << endl;
    return true;
}

bool sai::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    cout << "Comando não implementado" << endl;
    return true;
}

bool grava::executar(Jardim * jardim, string* argv, int argc) {

    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 1) {
        cout << "Uso: gravar <nome>" << endl;
        return false;
    }
    cout << "Comando não implementado" << endl;
    return true;
}

bool recupera::executar(Jardim * jardim, string* argv, int argc) {

    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 1) {
        cout << "Uso: gravar <nome>" << endl;
        return false;
    }
    cout << "Comando não implementado" << endl;
    return true;
}

bool apaga::executar(Jardim * jardim, string* argv, int argc) {

    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 1) {
        cout << "Uso: gravar <nome>" << endl;
        return false;
    }
    cout << "Comando não implementado" << endl;
    return true;
}

bool executa::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr) {
        cout << "Jardim não foi criado corretamente" << endl;
        return false;
    }
    if(argc != 1) {
        cout << "Uso: gravar <nome>" << endl;
        return false;
    }
    cout << "Comando não implementado" << endl;
    return true;
}


