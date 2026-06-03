#include "../include/Fabrica.h"
#include "../include/Controladores/ControladorFechaActual.h"
#include "../include/Controladores/ControladorUsuarios.h"
#include "../include/Controladores/ControladorViajes.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IControladorUsuarios* Fabrica::getIControladorUsuarios() {
    return ControladorUsuarios::getInstance();
}

IControladorViajes* Fabrica::getIControladorViajes() {
    return ControladorViajes::getInstance();
}

ICalificarUsuario* Fabrica::getICalificarUsuario() {
    return ControladorUsuarios::getInstance();
}

IEliminarViaje* Fabrica::getIEliminarViaje() {
    return ControladorViajes::getInstance();
}

IAltaUsuario* Fabrica::getIAltaUsuario() {
    return ControladorUsuarios::getInstance();
}

IAltaViaje* Fabrica::getIAltaViaje() {
    return ControladorViajes::getInstance();
}

IGenerarReserva* Fabrica::getIGenerarReserva() {
    return ControladorViajes::getInstance();
}