#include "../../include/Clases/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha)
{
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = nullptr;
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

void Reserva::setPasajero(Pasajero *pasajero)
{
    this->pasajero = pasajero;
}