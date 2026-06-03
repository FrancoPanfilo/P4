#ifndef FABRICA_H
#define FABRICA_H

#include "../Interfaces/IControladorFechaActual.h"
#include "../Interfaces/IControladorUsuarios.h"
#include "../Interfaces/IControladorViajes.h"

class Fabrica {
private:
    static Fabrica* instancia;

    Fabrica();

public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();
    IControladorUsuarios* getIControladorUsuarios();
    IControladorViajes* getIControladorViajes();

    ICalificarUsuario* getICalificarUsuario();
    IEliminarViaje* getIEliminarViaje();
    IAltaUsuario* getIAltaUsuario();
    IAltaViaje* getIAltaViaje();
    IGenerarReserva* getIGenerarReserva();
};

#endif
