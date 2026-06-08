#include "../../include/Manejadores/ManejadorVehiculos.h"

ManejadorVehiculos* ManejadorVehiculos::instancia = nullptr;

ManejadorVehiculos::ManejadorVehiculos() {}

ManejadorVehiculos* ManejadorVehiculos::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorVehiculos();
    }
    return instancia;
}

bool ManejadorVehiculos::existeVehiculo(std::string matricula) {
    return vehiculos.find(matricula) != vehiculos.end();
}

bool ManejadorVehiculos::agregarVehiculo(Vehiculo* vehiculo) {
    std::string matricula = vehiculo->getMatricula();
    if (existeVehiculo(matricula)) {
        return false;
    }
    vehiculos[matricula] = vehiculo;
    return true;
}

void ManejadorVehiculos::eliminarVehiculo(std::string matricula) {
    auto it = vehiculos.find(matricula);
    if (it != vehiculos.end()) {
        delete it->second;
        vehiculos.erase(it);
    }
}

Vehiculo* ManejadorVehiculos::getVehiculo(std::string matricula) {
    auto it = vehiculos.find(matricula);
    if (it == vehiculos.end()) {
        return nullptr;
    }
    return it->second;
}

Vehiculo* ManejadorVehiculos::nuevoVehiculo(std::string matricula, int capacidad,
                                            std::string marca, std::string modelo, TipoVehiculo tipo) {
    if (existeVehiculo(matricula)) {
        return nullptr;
    }

    Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    vehiculos[matricula] = v;
    return v;
}

ManejadorVehiculos::~ManejadorVehiculos() {
    for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        delete it->second;
    }
    vehiculos.clear();
}
