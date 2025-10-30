#include "Comando.h"

bool lplantas::executar(Jardim * jardim, string * argv, int argc) {
    if (jardim == nullptr)
        return false;

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

