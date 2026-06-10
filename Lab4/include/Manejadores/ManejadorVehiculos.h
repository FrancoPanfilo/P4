#ifndef MANEJADOR_VEHICULOS_H
#define MANEJADOR_VEHICULOS_H

#include <string>
#include <map>

#include "../Clases/Vehiculo.h"
#include "../DTyENUM/TipoVehiculo.h"

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

    Vehiculo* getVehiculo(std::string matricula);

    Vehiculo* nuevoVehiculo(std::string matricula, int capacidad,
                            std::string marca, std::string modelo, TipoVehiculo tipo);

    ~ManejadorVehiculos();
};

#endif
