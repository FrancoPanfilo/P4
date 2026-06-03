#ifndef MANEJADOR_VEHICULOS_H
#define MANEJADOR_VEHICULOS_H

#include <string>
#include <map>

#include "Vehiculo.h"

class ManejadorVehiculos {
private:
    static ManejadorVehiculos* instancia;

    std::map<std::string, Vehiculo*> vehiculos;

    ManejadorVehiculos();

public:
    static ManejadorVehiculos* getInstance();

    bool existeVehiculo(std::string matricula);

    bool agregarVehiculo(Vehiculo* vehiculo);

    void eliminarVehiculo(std::string matricula);

    getVehiculo(std::string matricula);  

    ~ManejadorVehiculo();
};

#endif
