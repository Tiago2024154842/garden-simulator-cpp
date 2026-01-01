#include "Jardineiro.h"
#include <sstream>

Jardineiro::Jardineiro() : mao(nullptr) {}
Jardineiro::~Jardineiro() {
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        delete (*it);
    }
}

void Jardineiro::setFerramenta(Ferramenta * f) {
    inventario.push_back(f);
}

std::string Jardineiro::getFerramentas() const {
    std::ostringstream str;

    if (mao != nullptr) {
        str << "--------- Mao ---------" << std::endl;
        str << mao->getDesc() << std::endl;
    }

    if (inventario.size() > 0) {
        str << "--------- Inventario (" << inventario.size() << ") ---------" << std::endl;
        for (auto it = inventario.begin(); it != inventario.end(); ++it)
            str << (*it)->getDesc() << std::endl;
    } else
        str << "Sem ferramentas no inventario" << std::endl;

    return str.str();
}

bool Jardineiro::pegaFerramenta(int num) {
    auto iterator = inventario.end();

    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if ((*it)->getNumSerie() == num)
            iterator = it;
    }

    if (iterator == inventario.end()) {
        std::cout << "Nao existe nenhuma ferramenta com esse numero de serie";
        return false;
    }

    Ferramenta* novaFerramenta = *iterator;
    inventario.erase(iterator);

    if (mao != nullptr)
        inventario.push_back(mao);

    mao = novaFerramenta;
    return true;
}
