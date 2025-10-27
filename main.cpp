#include <iostream>
#include <string>
#include <sstream>
#include "Comandos/ComandoFactory.h"

using namespace std;

void executarComando(const string & c) {
    istringstream comando(c);
    string nome;
    comando >> nome;

    Comando* cmd = ComandoFactory::criarComando(nome);

    if (cmd == nullptr) {
        cout << "Comando desconhecido" << endl;
        return;
    }

    string argv[3];
    int argc = 0;

    while (comando >> argv[argc] && argc < 3)
        argc++;


    cmd->executar();
}


int main() {
    string comando;

    cout << "Trabalho pratico POO - Tiago Maninha e Miguel Martins" << endl;
    do {
        cout << ">>";
        getline(cin, comando);
        executarComando(comando);
        comando.clear();
    } while (true);

    return 0;
}