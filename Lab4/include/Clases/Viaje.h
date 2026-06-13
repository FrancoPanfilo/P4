#ifndef VIAJE_H
#define VIAJE_H

#include "../DTyENUM/DTFecha.h"
#include "../DTyENUM/DTDetalleVehiculo.h"
#include "../DTyENUM/DTDetalleReserva.h"
#include "../DTyENUM/DTConsultaViaje.h"
#include "../DTyENUM/DTListarViaje.h"
#include <string>
#include <vector>

class Vehiculo;
class Reserva;

class Viaje
{
private:
    static int ultimoCodigo;

    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

    Vehiculo *vehiculo;
    std::vector<Reserva *> reservas;

public:
    Viaje(Vehiculo *vehiculo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();
    int obtenerCodigo();
    DTFecha getFecha();

    DTDetalleVehiculo getDTVehiculo();
    void agregarReserva(Reserva *reserva);
    //--
    Vehiculo* getVehiculo();
    std::vector<Reserva*> getReservas();
    DTListarViaje getDTListarViaje();
    //--
    std::vector<DTDetalleReserva> getDTReservas();

    bool cumpleCriterio(DTFecha fecha, std::string origen, std::string destino, int asientos);
    DTConsultaViaje getDTConsultaViaje(int asientos);
    bool puedeReservar(int asientos);
};

#endif
