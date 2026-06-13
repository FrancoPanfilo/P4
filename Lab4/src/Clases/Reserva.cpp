#include "../../include/Clases/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha)
{
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = nullptr;
    this->viaje = nullptr;
}

Reserva::~Reserva() {}
int Reserva::getAsientosReservados()
{
    return this->asientosReservados;
}

DTFecha Reserva::getFecha()
{
    return this->fecha;
}

Pasajero *Reserva::getPasajero()
{
    return this->pasajero;
}

Viaje* Reserva::getViaje() {
    return this->viaje;
}

void Reserva::setPasajero(Pasajero *pasajero)
{
    this->pasajero = pasajero;
}

void Reserva::setViaje(Viaje* viaje) {
    this->viaje = viaje;
}

//--
bool Reserva::reservaEsDeUsuario(std::string nickname) {
    return ((this->pasajero->getNickname()) == nickname);
}
//--