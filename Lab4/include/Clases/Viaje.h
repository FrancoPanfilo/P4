#ifndef VIAJE_H
#define VIAJE_H

#include "../DTyENUM/DTFecha.h"
#include "Vehiculo.h"
#include <string>
#include <vector>
class Reserva;


class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

    Vehiculo* vehiculo;
    std::vector<Reserva*> reservas;


public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();
    int obtenerCodigo();
    DTFecha getFecha();

    Vehiculo* getVehiculo();
    void agregarReserva(Reserva* reserva);
    std::vector<Reserva*> getReservas();

};

#endif
