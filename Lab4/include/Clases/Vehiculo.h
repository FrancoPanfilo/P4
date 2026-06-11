#ifndef VEHICULO_H
#define VEHICULO_H

#include "../DTyENUM/TipoVehiculo.h"
#include <string>
#include <list>

class Viaje;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::list<Viaje*> viajes;

    std::list<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();

    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();

    void agregarViaje(Viaje* viaje);
    std::list<Viaje*> getViajes();
};

#endif
