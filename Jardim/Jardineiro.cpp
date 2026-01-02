#include "Jardineiro.h"
#include <sstream>

Jardineiro::Jardineiro() : mao(nullptr) {}
Jardineiro::~Jardineiro() {
    for (auto it = inventario.begin(); it != inventario.end(); ++it)
        delete *it;
    
    inventario.clear();

    if (mao != nullptr) {
        delete mao;
        mao = nullptr;
    }
}

void Jardineiro::setFerramenta(Ferramenta * f) {
    inventario.push_back(f);
}

std::string Jardineiro::getFerramentas() const {
    std::ostringstream str;

    if (mao != nullptr) {
        str << "############# NA MAO #############" << std::endl;
        str << mao->getDesc() << std::endl;
    }

    if (inventario.size() > 0) {
        str << "############# INVENTARIO (" << inventario.size() << ") #############" << std::endl;
        for (auto it = inventario.begin(); it != inventario.end(); ++it)
            str << (*it)->getDesc() << std::endl;
    } else if (mao == nullptr)
        str << "Aviso: Sem ferramentas no inventario" << std::endl;

    return str.str();
}

void Jardineiro::pegaFerramenta(int num) {
    auto iterator = inventario.end();

    if (mao != nullptr && mao->getNumSerie() == num) {
        std::cout << "Erro: O jardineiro ja tem essa ferramenta na mao" << std::endl;
        return;
    }

    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if ((*it)->getNumSerie() == num) {
            iterator = it;
            break;
        }
    }

    if (iterator == inventario.end()) {
        std::cout << "Erro: Nao existe nenhuma ferramenta no inventario do jardineiro com esse numero de serie" << std::endl;
        return;
    }

    Ferramenta* novaFerramenta = *iterator;
    inventario.erase(iterator);

    if (mao != nullptr)
        inventario.push_back(mao);

    mao = novaFerramenta;
    std::cout << mao->getNome() << " (nr de serie: " << num << ") posta na mao do jardineiro" << std::endl;
}

void Jardineiro::largaFerramenta() {
    if (mao != nullptr) {
        inventario.push_back(mao);
        std::cout << mao->getNome() << " largado(a)" << std::endl;
        mao = nullptr;
    } else {
        std::cout << "Erro: O jardineiro nao tem nenhuma ferramenta para largar" << std::endl;
    }
}   