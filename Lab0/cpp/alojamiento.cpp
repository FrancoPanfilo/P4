#include "../h/alojamiento.h"
#include <iostream>

using namespace std;

Alojamiento::Alojamiento(string codigoReserva,
                         string descripcion,
                         int precio,
                         DTFecha fecha,
                         string hotel,
                         TipoRegimen regimen,
                         int cantidadNoches)
    : Experiencia(codigoReserva, descripcion, precio, fecha)
{
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantidadNoches = cantidadNoches;
}

Alojamiento::~Alojamiento() {}

int Alojamiento::getCantNoches() const
{
    return this->cantidadNoches;
}

float Alojamiento::calcularCosto() const
{
    float costo = 0;
    if (regimen == MediaPension)
        costo = this->getPrecioBase() * getCantNoches();
    else
        costo = (this->getPrecioBase() + 10) * getCantNoches();
    return costo;
}