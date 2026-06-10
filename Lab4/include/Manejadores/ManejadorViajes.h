#ifndef MANEJADOR_VIAJE_H
#define MANEJADOR_VIAJE_H

#include <string>
#include <set>
#include <map>

#include "../Clases/Viaje.h"
#include "../DTyENUM/DTFecha.h"
#include "../DTyENUM/DTConsultaViaje.h"

class ManejadorViaje {
private:
    static ManejadorViajes* instancia;

    std::map<int, Viaje*> viajes;

    ManejadorViajes();

public:
    static ManejadorViajes* getInstance();

    Viaje* obtenerViaje(int codigo);

    std::set<DTConsultaViaje> consultarViajes(
        DTFecha fecha,
        std::string origen,
        std::string destino,
        int asientos
    );

    //float obtenerCalificacion(std::string nickname);
    
    //void agregarCalificacion(int codigoViaje, int puntaje);

    Viaje* crearViaje(
        int codigo,
        DTFecha fecha,
        std::string origen,
        std::string destino,
        int asientos,
        int precio
    );

    ~ManejadorViajes();
};

#endif
