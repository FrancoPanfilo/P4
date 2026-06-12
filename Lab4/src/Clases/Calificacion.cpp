#include "../../include/Clases/Calificacion.h"

//---
Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario* calificador, Reserva* reserva)
{
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->reserva = reserva;
    this->calificador = calificador;
}
//---

Calificacion::~Calificacion() {}

int Calificacion::getPuntaje(){
    return this->puntaje;
}

//---
Usuario* Calificacion::getCalificador()
{
    return calificador;
}

DTFecha Calificacion::getFecha()
{
    return fecha;
}

Reserva* Calificacion::getReserva()
{
    return reserva;
}
//---