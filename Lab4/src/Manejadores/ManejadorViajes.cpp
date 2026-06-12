#include "../../include/Manejadores/ManejadorViajes.h"

ManejadorViajes* ManejadorViajes::instancia = nullptr;

ManejadorViajes::ManejadorViajes() {}

ManejadorViajes* ManejadorViajes::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorViajes();
    }
    return instancia;
}

Viaje* ManejadorViajes::obtenerViaje(int codigo) {
    auto it = viajes.find(codigo);

    if (it == viajes.end()) {
        return nullptr;
    }

    return it->second;
}

std::vector<DTConsultaViaje> ManejadorViajes::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {

    //Devuelve la información de los viajes que cumplen con las condiciones de búsqueda con la información del conductor y vehículo del mismo.

    // (DSC Generar Reserva: DCM consultarViajes )

    std::vector<DTConsultaViaje> resultado;

    // 1.1* [foreach]: v := next()
    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        Viaje* v = it->second;

        // 1.2* cumple
        bool cumple = v->cumpleCriterio(fecha, origen, destino, asientos);

        // 1.3* [cumple]
        if (cumple) {
            DTConsultaViaje dtcv = v->getDTConsultaViaje(asientos);
            resultado.push_back(dtcv);
        }
    }

    return resultado;
}

Reserva* ManejadorViajes::getReservaUsuarioCalificado(int codigoViaje, std::string nicknameCalificado) {

    //Busca la reserva del usuario calificado dentro del viaje recordado en memoria, y la retorna.
    // (DSC Calificar Usuarios: DCM calificarUsuario: getReservaUsuarioCalificado)

    // 2: v := find(codigo)
    Viaje* v = obtenerViaje(codigoViaje);

    if (v == nullptr) { return nullptr; }

    // 2.1: getReservas()
    std::vector<Reserva*> reservas = v->getReservas();

    // 2.2* [foreach] r := next()
    for (auto it = reservas.begin(); it != reservas.end(); ++it) {
        Reserva* r = *it;

        // 2.2.1: reservaEsDeUsuario(nicknameCalificado)
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
