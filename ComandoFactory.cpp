#include "ComandoFactory.h"

Comando * ComandoFactory::criarComando(const std::string & comando) {
    if (comando == "lplantas") return new lplantas();
    if (comando == "planta") return new planta();
    if (comando == "lplanta") return new lplanta();
    if (comando == "avanca") return new avanca();
    if (comando == "larea") return new larea();
    if (comando == "lsolo") return new lsolo();
    if (comando == "lferr") return new lferr();
    if (comando == "colhe") return new colhe();
    if (comando == "larga") return new larga();
    if (comando == "compra") return new compra();
    if (comando == "pega") return new pega();
    if (comando == "e") return new mover('e');
    if (comando == "d") return new mover('d');
    if (comando == "c") return new mover('c');
    if (comando == "b") return new mover('b');
    if (comando == "entra") return new entra();
    if (comando == "sai") return new sai();
    if (comando == "grava") return new grava();
    if (comando == "recupera") return new recupera();
    if (comando == "apaga") return new apaga();
    if (comando == "executa") return new executa();
    return nullptr;
}

Jardim * ComandoFactory::executarComando(const string& c, Jardim* jardimAtual) {
    istringstream comando(c);
    string nome;
    comando >> nome;

    if (nome == "jardim") {
        int linhas, colunas;
        if (comando >> linhas >> colunas) {
            if (linhas > 26 || colunas > 26) {
                cout << "Erro: O tamanho maximo e 26x26" << endl;
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

    Comando* cmd = criarComando(nome);
    if (cmd == nullptr) {
        cout << "Erro: Comando desconhecido" << endl;
        return jardimAtual;
    }

    string argv[2];
    int argc = 0;
    while (comando >> argv[argc] && argc < 3)
        argc++;

    if (cmd->executar(jardimAtual, argv, argc)) // se retornar true mostra o jardim
        jardimAtual->mostraGrelha();

    delete cmd;
    
    return jardimAtual;
}