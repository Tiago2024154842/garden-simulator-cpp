#ifndef JARDIM_H
#define JARDIM_H

#include "Comando.h"

class jardim : public Comando {
public:
    bool executar() override;
};

#endif //JARDIM_H
