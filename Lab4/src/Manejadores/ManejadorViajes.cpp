#include "../../include/Manejadores/ManejadorViajes.h"
#include <algorithm>

ManejadorViajes* ManejadorViajes::instancia = nullptr;

ManejadorViajes::ManejadorViajes() {}

ManejadorViajes* ManejadorViajes::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorViajes();
    }
    return instancia;
}

std::map<int,Viaje*> ManejadorViajes::getViajes() {
    return this->viajes;
}

Viaje* ManejadorViajes::obtenerViaje(int codigo) {
    auto it = viajes.find(codigo);

    if (it == viajes.end()) {
        return nullptr;
    }

    return it->second;
}

void ManejadorViajes::eliminarViaje(int codigo) {
    viajes.erase(codigo);
}

std::vector<DTConsultaViaje> ManejadorViajes::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {

    //Devuelve la información de los viajes que cumplen con las condiciones de búsqueda con la información del conductor y vehículo del mismo.

    std::vector<DTConsultaViaje> resultado;

    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        Viaje* v = it->second;

        bool cumple = v->cumpleCriterio(fecha, origen, destino, asientos);

        if (cumple) {
            DTConsultaViaje dtcv = v->getDTConsultaViaje(asientos);
            resultado.push_back(dtcv);
        }
    }

    std::sort(resultado.begin(), resultado.end(), [](DTConsultaViaje a, DTConsultaViaje b) {
        if (a.getPrecioTotal() != b.getPrecioTotal()) {
            return a.getPrecioTotal() < b.getPrecioTotal();
        }
        return a.getCalificacionProm() > b.getCalificacionProm();
    });

    return resultado;
}

Reserva* ManejadorViajes::getReservaUsuarioCalificado(int codigoViaje, std::string nicknameCalificado) {

    //Busca la reserva del usuario calificado dentro del viaje recordado en memoria, y la retorna.

    Viaje* v = obtenerViaje(codigoViaje);

    if (v == nullptr) { return nullptr; }

    std::vector<Reserva*> reservas = v->getReservas();

    for (auto it = reservas.begin(); it != reservas.end(); ++it) {
        Reserva* r = *it;

        if (r->reservaEsDeUsuario(nicknameCalificado)) {
            return r;
        }
    }

    return nullptr;
}


Viaje* ManejadorViajes::crearViaje(Vehiculo* vehiculo, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
    Viaje* v = new Viaje(vehiculo, fecha, origen, destino, asientos, precio);

    viajes[v->obtenerCodigo()] = v;

    return v;
}

ManejadorViajes::~ManejadorViajes() {
    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        delete it->second;
    }

    viajes.clear();
}
