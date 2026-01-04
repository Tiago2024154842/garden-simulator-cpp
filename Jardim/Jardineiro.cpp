#include "Jardineiro.h"
#include "Settings.h"
#include <sstream>

Jardineiro::Jardineiro() : mao(nullptr), noJardim(false), linha(-1), coluna(-1) {
    resetContadoresTurno();
}

Jardineiro::Jardineiro(const Jardineiro & outro) {
    noJardim = outro.noJardim;
    linha = outro.linha;
    coluna = outro.coluna;
    movimentosTurno = outro.movimentosTurno;
    colheitasTurno = outro.colheitasTurno;
    plantacoesTurno = outro.plantacoesTurno;
    saidasTurno = outro.saidasTurno;
    entradasTurno = outro.entradasTurno;

    for (auto f : outro.inventario) 
        inventario.push_back(f->copia());

    if (outro.mao != nullptr)
        mao = outro.mao->copia();
    else
        mao = nullptr;
}

Jardineiro::~Jardineiro() {
    for (auto it = inventario.begin(); it != inventario.end(); ++it)
        delete *it;
    
    inventario.clear();

    if (mao != nullptr) {
        delete mao;
        mao = nullptr;
    }
}

bool Jardineiro::estaNoJardim() const { return noJardim; }

bool Jardineiro::estaNaPosicao(int l, int c) const {
    return noJardim && linha == l && coluna == c;
}

void Jardineiro::setPosicao(int l, int c) {
    linha = l;
    coluna = c;
    noJardim = true;
}

int Jardineiro::getLinha() const { return linha; }

int Jardineiro::getColuna() const { return coluna; }

void Jardineiro::resetContadoresTurno() {
    saidasTurno = 0;
    entradasTurno = 0;
    movimentosTurno = 0;
    colheitasTurno = 0;
    plantacoesTurno = 0;
}

bool Jardineiro::podeMover() const { return movimentosTurno < Settings::Jardineiro::max_movimentos; }

bool Jardineiro::podeColher() const { return colheitasTurno < Settings::Jardineiro::max_colheitas; }

bool Jardineiro::podePlantar() const { return plantacoesTurno < Settings::Jardineiro::max_plantacoes; }

bool Jardineiro::podeSair() const { return saidasTurno < Settings::Jardineiro::max_entradas_saidas; }

bool Jardineiro::podeEntrar() const { return entradasTurno < Settings::Jardineiro::max_entradas_saidas; }

void Jardineiro::registarMovimento() {
    ++movimentosTurno;
}

void Jardineiro::registarColheita() {
    ++colheitasTurno;
}

void Jardineiro::registarPlantacao() {
    ++plantacoesTurno;
}

void Jardineiro::registarEntrada() {
    ++entradasTurno;
    noJardim = true;
}

void Jardineiro::sairDoJardim() {
    ++saidasTurno;
    noJardim = false;
}

void Jardineiro::setFerramenta(Ferramenta * f) {
    if (f != nullptr)
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
    } else 
        std::cout << "Erro: O jardineiro nao tem nenhuma ferramenta para largar" << std::endl;
}   

void Jardineiro::usarFerramenta(Celula * area) {
    if (mao != nullptr && area != nullptr) {
        bool eliminar = !mao->usar(area);

        if (eliminar) {
            delete mao;
            mao = nullptr;
        }
    }
}