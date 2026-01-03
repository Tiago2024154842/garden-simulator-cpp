#include "Comando.h"
#include "ComandoFactory.h"
#include <fstream>

bool lplantas::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    jardim->listarPlantas();
    return false;
}

bool lplanta::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    if (argc != 1 || argv[0].length() != 2) {
        cout << "Uso: lplanta <linha><coluna>" << endl;
        return false;
    }

    int l = (int) argv[0][0] - (int) 'a';
    int c = (int) argv[0][1] - (int) 'a';

    if(l >= jardim->getNLinhas() || c >= jardim->getNColunas() || l < 0 || c < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    jardim->getDescPlanta(l, c);
    return false;
}

bool planta::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    if (argc != 2 || argv[0].length() != 2) {
        cout << "Uso: planta <linha><coluna> <tipo>" << endl;
        return false;
    }

    int l = (int) argv[0][0] - (int) 'a';
    int c = (int) argv[0][1] - (int) 'a';

    if(l >= jardim->getNLinhas() || c >= jardim->getNColunas() || l < 0 || c < 0) {
        cout << "Erro: Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    if (!(argv[1] == "c" || argv[1] == "r" || argv[1] == "e" || argv[1] == "x")) {
        cout << "Erro: <tipo> errado, as opcoes sao [c] [r] [e] [x] "<< endl;
        return false;
    }

    return jardim->criarPlanta(l, c, argv[1][0]);;
}

bool avanca::executar(Jardim *jardim, string *argv, int argc) {
    if (jardim == nullptr)
        return false;

    int n = 1;
    if (argc > 0) {
        n = stoi(argv[0]);
        if(n < 0) {
            cout << "Erro: [n] tem de ser numero positivo" << endl;
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

    jardim->listaArea();
    return false;
}

bool lsolo::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;
    
    if ((argc != 1 && argc != 2) || argv[0].length() != 2) {
        cout << "Uso: lsolo <linha><coluna> [n]" << endl;
        return false;
    }

    int l = (int) argv[0][0] - (int) 'a';
    int c = (int) argv[0][1] - (int) 'a';

    if(l >= jardim->getNLinhas() || c >= jardim->getNColunas() || l < 0 || c < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    if (argc == 2) {
        int n = stoi(argv[1]);
        if(n < 0) {
            cout << "[n] tem de ser numero positivo" << endl;
            return false;
        }

        jardim->listaSolo(l, c, n);
        return false;
    }

    jardim->listaSolo(l, c);
    return false;
}

bool lferr::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

    jardim->listaFerramentas();
    return false;
}

bool colhe::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    if (argc != 1 || argv[0].length() != 2) {
        cout << "Uso: colhe <linha><coluna>" << endl;
        return false;
    }

    int l = (int) argv[0][0] - (int) 'a';
    int c = (int) argv[0][1] - (int) 'a';

    if(l >= jardim->getNLinhas() || c >= jardim->getNColunas() || l < 0 || c < 0) {
        cout << "Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    return jardim->removerPlanta(l, c);
}

bool larga::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    jardim->largaFerramenta();
    return false;
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

    jardim->pegaFerramenta(n);
    return false;
}

bool compra::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;
    
    if (argc != 1) {
        cout << "Uso: compra <c>" << endl;
        return false;
    }

    char simbolo = argv[0][0];

    if (!(simbolo == 'g' || simbolo == 'a' || simbolo == 't' || simbolo == 'z')) {
        cout << "Erro: <c> errado, as opcoes sao [g] [a] [t] [z] "<< endl;
        return false;
    }

    jardim->compraFerramenta(simbolo);
    return false;
}

mover::mover(char d) : direcao(d) {};

bool mover::executar(Jardim *jardim, string *argv, int argc) {
    if (jardim == nullptr)
        return false;

    return jardim->moverJardineiro(direcao);
}

bool entra::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    if(argc != 1 || argv[0].length() != 2) {
        cout << "Uso: entra <linha><coluna>" << endl;
        return false;
    }

    int l = (int) argv[0][0] - (int) 'a';
    int c = (int) argv[0][1] - (int) 'a';

    if(l >= jardim->getNLinhas() || c >= jardim->getNColunas() || l < 0 || c < 0) {
        cout << "Erro: Coordenadas fora dos limites do jardim" << endl;
        return false;
    }

    return jardim->setJardineiro(l, c);
}

bool sai::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    return jardim->sairJardineiro();
}

bool grava::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;
        
    if (argc != 1) {
        cout << "Uso: gravar <nome>" << endl;
        return false;
    }

    ComandoFactory::gravar(argv[0], jardim);
    return false;
}

bool recupera::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;
    
    if(argc != 1) {
        cout << "Uso: recupera <nome>" << endl;
        return false;
    }

    return ComandoFactory::recuperar(argv[0], jardim);;
}

bool apaga::executar(Jardim * jardim, string* argv, int argc) {
    if (jardim == nullptr)
        return false;

    if (argc != 1) {
        cout << "Uso: apaga <nome>" << endl;
        return false;
    }

    ComandoFactory::apagar(argv[0]);
    return false;
}

bool executa::executar(Jardim * jardim, string* argv, int argc) {
    if (argc != 1) {
        cout << "Uso: executa <nome>" << endl;
        return false;
    }

    ifstream inputFile(argv[0]);
    if (!inputFile.is_open()) {
        cout << "Erro ao abrir o ficheiro " << argv[0] << endl;
        return false;
    }

    cout << "Comando não implementado" << endl;
    return true;
}


