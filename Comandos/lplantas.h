#ifndef LPLANTAS_H
#define LPLANTAS_H

#include "Comando.h"

class lplantas : public Comando {
public:
    bool executar() override;
};

#endif
