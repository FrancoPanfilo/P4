#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IControladorUsuarios.h"
#include "IControladorViajes.h"

class Fabrica {
private:
    static Fabrica* instancia;

    Fabrica();

public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();
    IControladorUsuarios* getIControladorUsuarios();
    IControladorViajes* getIControladorViajes();
};

#endif
