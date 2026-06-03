#include "../include/Clases/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio)
{
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {}

Viaje::getFecha(){
    return this->fecha;
}

Viaje::obtenerCodigo(){
    return this->codigo;
}

