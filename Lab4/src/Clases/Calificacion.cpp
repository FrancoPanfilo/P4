#include "../../include/Clases/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

int Calificacion::getPuntaje(){
    return this->puntaje;
}
