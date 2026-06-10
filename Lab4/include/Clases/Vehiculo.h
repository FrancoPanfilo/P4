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
    std::list<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();

    std::string getMatricula();
    int getCapacidad();
};

#endif
