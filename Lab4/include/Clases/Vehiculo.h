#ifndef VEHICULO_H
#define VEHICULO_H

#include "../DTyENUM/TipoVehiculo.h"
#include <string>

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    void registrarVehiculo(std::string matricula);
    DTVehiculo getDTVehiculo();
    int getCapacidad();
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    void asociarViaje(int codigoViaje);
};

#endif
