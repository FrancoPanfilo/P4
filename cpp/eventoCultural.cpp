#include "../h/eventoCultural.h"
#include <iostream>

EventoCultural::EventoCultural(std::string codigoReserva,
                               std::string descripcion,
                               int precioBase,
                               DTFecha fecha,
                               std::string ubicacion,
                               bool usoCupon)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha) {}

EventoCultural::~EventoCultural() {}

std::string EventoCultural::getUbicacion() const
{
    return ubicacion;
}

bool EventoCultural::getUsoCupon() const
{
    return usoCupon;
}

float EventoCultural::calcularCosto() const
{
    int cantidadTuristas = turistas.size();

    float costo = precioBase * cantidadTuristas;

    if (usoCupon)
    {
        costo = costo - (5 * cantidadTuristas);
    }

    return costo;
}