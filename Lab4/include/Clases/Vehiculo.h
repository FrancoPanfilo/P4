#ifndef VEHICULO_H
#define VEHICULO_H

#include "../DTyENUM/TipoVehiculo.h"
#include <string>
#include <vector>
#include "Viaje.h"

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

    std::string getMatricula();
    int getCapacidad();

    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    
};

#endif
