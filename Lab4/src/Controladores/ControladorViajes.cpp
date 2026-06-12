#include "../../include/Controladores/ControladorViajes.h"
#include "../../include/Manejadores/ManejadorUsuarios.h"
#include "../../include/Manejadores/ManejadorVehiculos.h"
#include "../../include/Manejadores/ManejadorViajes.h"
#include "../../include/Controladores/ControladorFechaActual.h"
#include "../../include/Clases/Vehiculo.h"
#include "../../include/Clases/Viaje.h"
#include "../../include/Clases/Reserva.h"
#include "../../include/Clases/Pasajero.h"
#include "../../include/DTyENUM/DTDetalleVehiculo.h"
#include "../../include/DTyENUM/DTDetalleReserva.h"
#include <vector>

ControladorViajes* ControladorViajes::instancia = nullptr;

ControladorViajes::ControladorViajes() {
    codigoMemoria = 0;
}

ControladorViajes* ControladorViajes::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorViajes();
    }
    return instancia;
}

std::vector<DTVehiculosConductor> ControladorViajes::listarVehiculosConductor(std::string nickname) {
    return std::vector<DTVehiculosConductor>();
}

bool ControladorViajes::altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                                  std::string destino, int asientos, float precio) {
    Vehiculo* v = ManejadorVehiculos::getInstance()->getVehiculo(matricula);

    if (v == nullptr) {
        return false;
    }

    if (v->getCapacidad() < asientos) {
        return false;
    }

    if (v->hayViajesConductor(fecha)) {
        return false;
    }

    Viaje* viaje = ManejadorViajes::getInstance()->crearViaje(v, fecha, origen, destino, asientos, precio);
    v->asociarViaje(viaje);

    return true;
}

std::vector<std::string> ControladorViajes::listarPasajeros() {
    return ManejadorUsuarios::getInstance()->listarPasajeros();
}

std::vector<DTConsultaViaje> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen,
                                                             std::string destino, int asientos) {
    return ManejadorViajes::getInstance()->consultarViajes(fecha, origen, destino, asientos);
}

bool ControladorViajes::generarReserva(std::string nickname, int codigo, int asientos) {
    Viaje* vi = ManejadorViajes::getInstance()->obtenerViaje(codigo);
    if (vi == nullptr) {
        return false;
    }

    Pasajero* p = ManejadorUsuarios::getInstance()->findPasajero(nickname);
    if (p == nullptr) {
        return false;
    }

    if (!vi->puedeReservar(asientos)) {
        return false;
    }

    DTFecha fechaActual = ControladorFechaActual::getInstance()->getFecha();
    Reserva* re = new Reserva(asientos, fechaActual);
    re->setPasajero(p);

    vi->agregarReserva(re);
    p->agregarReserva(re);

    return true;
}

std::vector<DTListarViaje> ControladorViajes::listarViajes() {
    return std::vector<DTListarViaje>();
}

DTDetalleViaje ControladorViajes::detalleViaje(int codigo) {
    codigoMemoria = codigo;
    DTDetalleVehiculo vehiculo("", 0, "", "", Auto);
    return DTDetalleViaje(0, DTFecha(1, 1, 2024), "", "", 0, 0.0f,
                          vehiculo, std::vector<DTDetalleReserva>());
}

void ControladorViajes::eliminarViaje() {
}

void ControladorViajes::cancelarEliminarViaje() {
}
