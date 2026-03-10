#include "../h/alojamiento.h"
#include <iostream>

Alojamiento::Alojamiento(std::string codigoReserva, std::string nombre, double precio, std::string hotel, TipoRegimen regimen, int cantidadNoches)
    : Experiencia(codigoReserva, nombre, precio), hotel(hotel), regimen(regimen), cantidadNoches(cantidadNoches) {}

Alojamiento::~Alojamiento() {}

int Alojamiento::getCantNoches()
{
    return this->cantidadNoches;
}

float Alojamiento::calcularCosto()
{
    float costo = 0;
    if (regimen == MediaPension)
        costo = getPrecioBase() * getCantNoches();
    else
        costo = (getPrecioBase() + 10) * getCantNoches();
    return costo;
}