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
    re->setViaje(vi);
    vi->agregarReserva(re);
    p->agregarReserva(re);

    return true;
}

std::vector<std::string> ControladorViajes::listarPasajeros() {
    return ManejadorUsuarios::getInstance()->listarPasajeros();
}

std::vector<DTListarViaje> ControladorViajes::listarViajes() {
        
    std::vector<DTListarViaje> res;

    std::map<int, Viaje*> viajes = ManejadorViajes::getInstance()->getViajes();

    for (auto const& par : viajes) {
        Viaje* viaje = par.second;

        DTListarViaje dt = viaje->getDTListarViaje();
        res.push_back(dt);
    }

    return res;

}

std::vector<DTVehiculosConductor> ControladorViajes::listarVehiculosConductor(std::string nickname) {

    std::vector<DTVehiculosConductor> res;

    Conductor* conductor = ManejadorUsuarios::getInstance()->findConductor(nickname);

    if (conductor == nullptr){ return res; }
        
    std::list<Vehiculo*> vehiculos = conductor->getVehiculos();

    for (Vehiculo* v : vehiculos) {
        DTVehiculosConductor dt(v->getMatricula(), v->getModelo(), v->getCapacidad());
        res.push_back(dt);
    }

    return res;
}

DTDetalleViaje ControladorViajes::detalleViaje(int codigo) {
    codigoMemoria = codigo;

    Viaje* viaje = ManejadorViajes::getInstance()->obtenerViaje(codigo);

    return viaje->getDTDetalleViaje();
}

void ControladorViajes::eliminarViaje() {
    Viaje* viaje = ManejadorViajes::getInstance()->obtenerViaje(codigoMemoria);

    if (viaje == nullptr) {
        return;
    }

    Vehiculo* vehiculo = viaje->getVehiculo();

    if (vehiculo != nullptr) {
        vehiculo->quitarViaje(viaje);
    }

    std::vector<Reserva*> reservas = viaje->getReservas();

    for (Reserva* reserva : reservas) {
        Pasajero* pasajero = reserva->getPasajero();

        if (pasajero != nullptr) {
            pasajero->quitarReserva(reserva);
        }

        delete reserva;
    }

    viaje->vaciarReservas();

    ManejadorViajes::getInstance()->eliminarViaje(this->codigoMemoria);

    delete viaje;

    this->codigoMemoria = 0;
}

void ControladorViajes::cancelarEliminarViaje() {
    this->codigoMemoria = 0;
}
