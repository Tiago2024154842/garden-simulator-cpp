#include <iostream>
#include <string>
#include <sstream>
#include "Jardim/Jardim.h"
#include "ComandoFactory.h"

using namespace std;

int main() {
    string comando;
    Jardim* jardim = nullptr;
    
    cout << "Trabalho pratico POO - Tiago Maninha e Miguel Martins" << endl;
    do {
        cout << ">>";
        getline(cin, comando);
        if (comando == "fim") break;
        
        jardim = executarComando(comando, jardim);
        comando.clear();
    } while (true);

    delete jardim;
    return 0;
}