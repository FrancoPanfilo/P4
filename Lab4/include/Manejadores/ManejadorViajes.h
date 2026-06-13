#ifndef MANEJADOR_VIAJE_H
#define MANEJADOR_VIAJE_H

#include <string>
#include <vector>
#include <map>
#include <list>

#include "../Clases/Reserva.h"
#include "../Clases/Viaje.h"
#include "../DTyENUM/DTFecha.h"
#include "../DTyENUM/DTConsultaViaje.h"

class Vehiculo;

class ManejadorViajes {
private:
    static ManejadorViajes* instancia;

    std::map<int, Viaje*> viajes;

    ManejadorViajes();

public:
    static ManejadorViajes* getInstance();

    Viaje* obtenerViaje(int codigo);

    std::vector<DTConsultaViaje> consultarViajes(
        DTFecha fecha,
        std::string origen,
        std::string destino,
        int asientos
    );

    Reserva* getReservaUsuarioCalificado(int codigoViaje, std::string nicknameCalificado);

    Viaje* crearViaje(
        Vehiculo* vehiculo,
        DTFecha fecha,
        std::string origen,
        std::string destino,
        int asientos,
        float precio
    );

    std::map<int, Viaje*> getViajes();

    void eliminarViaje(int codigo);

    ~ManejadorViajes();
};

#endif
