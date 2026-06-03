#ifndef VIAJE_H
#define VIAJE_H

#include "../DTyENUM/DTFecha.h"
#include <string>

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();
    bool cumpleCreiterio(DTFecha fecha, std::string origen, std::string destino, int asientos);
    DTVehiculo getVehiculo();
    DTDetalleReserva getReservas();
    int obtenerCodigo();
    DTFecha getFecha();
};

#endif
