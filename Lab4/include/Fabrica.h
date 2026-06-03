#ifndef FABRICA_H
#define FABRICA_H

#include "Interfaces/IControladorFechaActual.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/ICalificarUsuario.h"
#include "Interfaces/IAltaViaje.h"
#include "Interfaces/IGenerarReserva.h"
#include "Interfaces/IEliminarViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;

    Fabrica();

public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();

    ICalificarUsuario* getICalificarUsuario();
    IAltaUsuario* getIAltaUsuario();

    IAltaViaje* getIAltaViaje();
    IGenerarReserva* getIGenerarReserva();
    IEliminarViaje* getIEliminarViaje();
};

#endif
