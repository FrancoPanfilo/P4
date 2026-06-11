#include "../../include/Clases/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha)
{
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
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