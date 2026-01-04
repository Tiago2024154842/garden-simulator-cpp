#include "ComandoFactory.h"
#include <sstream>

std::unordered_map<std::string, Jardim*> ComandoFactory::gravacoes;

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

Jardim * ComandoFactory::executarComando(const std::string& c, Jardim* jardimAtual) {
    istringstream comando(c);
    string nome;
    comando >> nome;

    if (nome == "jardim") {
        int linhas, colunas;
        if (comando >> linhas >> colunas) {
            if (linhas > 26 || colunas > 26) {
                cout << "Erro: O tamanho maximo e 26x26" << endl;
                return jardimAtual;
            } else if (linhas < 0 || colunas < 0) {
                cout << "Erro: O tamanho do jardim nao pode ser negativo" << endl;
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
    while (argc < 2 && comando >> argv[argc])
        argc++;

    if (cmd->executar(jardimAtual, argv, argc)) // se retornar true mostra o jardim
        jardimAtual->mostraGrelha();

    delete cmd;
    
    return jardimAtual;
}

void ComandoFactory::gravar(const string & nome, Jardim* jardimAtual) {
    if (jardimAtual == nullptr) return;

    auto it = gravacoes.find(nome);
    if (it != gravacoes.end())
        delete it->second;

    gravacoes[nome] = new Jardim(*jardimAtual);
    std::cout << "Copia do jardim guardada com o nome " << nome << endl;
}

bool ComandoFactory::recuperar(const std::string & nome, Jardim* jardimAtual) {
    if (jardimAtual == nullptr) return false;

    auto it = gravacoes.find(nome);
    if (it == gravacoes.end()) {
        std::cout << "Erro: Gravacao nao encontrada" << std::endl;
        return false;
    }

    Jardim* save = it->second;

    *jardimAtual = *save;
    delete save;
    gravacoes.erase(it);

    std::cout << "Jardim recuperado e gravacao eliminada da memoria" << endl;
    return true;
}

bool ComandoFactory::apagar(const std::string & nome) {
    auto it = gravacoes.find(nome);
    if (it == gravacoes.end()) {
        std::cout << "Erro: Gravacao nao encontrada" << std::endl;
        return false;
    }

    delete it->second;
    gravacoes.erase(it);

    std::cout << "Gravacao eliminada" << endl;
    return true;
}