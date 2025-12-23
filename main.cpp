#include <iostream>
#include <string>
#include <sstream>
#include "Jardim/Jardim.h"
#include "ComandoFactory.h"

using namespace std;

Jardim* executarComando(const string& c, Jardim* jardimAtual) {
    istringstream comando(c);
    string nome;
    comando >> nome;

    if (nome == "jardim") {
        int linhas, colunas;
        if (comando >> linhas >> colunas) {
            if (linhas > 26 || colunas > 26) {
                cout << "Erro: O tamanho maximo e 26x26!" << endl;
                return jardimAtual;
            }

            delete jardimAtual;
            return new Jardim(linhas, colunas);
        }
        cout << "Uso: jardim <nlinhas> <ncolunas>" << endl;
        return jardimAtual;
    }

    if (jardimAtual == nullptr && nome != "fim" && nome != "executa") {
        cout << "Erro: Primeiro crie um jardim usando 'jardim <nlinhas> <ncolunas>'" << endl;
        return nullptr;
    }

    Comando* cmd = ComandoFactory::criarComando(nome);
    if (cmd == nullptr) {
        cout << "Comando desconhecido" << endl;
        return jardimAtual;
    }

    string argv[2];
    int argc = 0;
    while (comando >> argv[argc] && argc < 3)
        argc++;

    if (cmd->executar(jardimAtual, argv, argc))
        jardimAtual->mostraGrelha();

    delete cmd;
    
    return jardimAtual;
}

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