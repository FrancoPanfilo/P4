#include "../../include/Clases/Vehiculo.h"
#include "../../include/Clases/Viaje.h"
#include "../../include/Clases/Conductor.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->conductor = nullptr;
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

std::string Vehiculo::getNombreConductor() {
    return conductor->getNombre();
}

float Vehiculo::getCalPromConductor() {
    return conductor->getCalProm();
}

void Vehiculo::setConductor(Conductor *conductor) {
    this->conductor = conductor;
}

void Vehiculo::asociarViaje(Viaje* viaje) {
    viajes.push_back(viaje);
}

std::list<Viaje*> Vehiculo::getViajes() {
    return viajes;
}

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
    return conductor->hayViajesFechaConductor(fecha);
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    for (Viaje* v : viajes) {
        if (v->getFecha() == fecha) {
            return true;
        }
    }
    return false;
}
