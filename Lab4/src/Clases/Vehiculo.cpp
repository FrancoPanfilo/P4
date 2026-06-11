#include "../../include/Clases/Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

Vehiculo::~Vehiculo() {}

std::string Vehiculo::getMatricula() {
    return matricula;
}

int Vehiculo::getCapacidad() {
    return capacidad;
}

std::string Vehiculo::getMarca() {
    return marca;
}

std::string Vehiculo::getModelo() {
    return modelo;
}

TipoVehiculo Vehiculo::getTipo() {
    return tipo;
}

void Vehiculo::agregarViaje(Viaje* viaje) {
    viajes.push_back(viaje);
}

std::list<Viaje*> Vehiculo::getViajes() {
    return viajes;
}
