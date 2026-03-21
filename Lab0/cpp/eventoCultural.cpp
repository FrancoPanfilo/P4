#include "../h/eventoCultural.h"
#include <iostream>

using namespace std;

EventoCultural::EventoCultural(string codigoReserva,
                               string descripcion,
                               int precioBase,
                               DTFecha fecha,
                               string ubicacion,
                               bool usoCupon)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha),
      ubicacion(ubicacion),
      usoCupon(usoCupon) {}

EventoCultural::~EventoCultural() {}

string EventoCultural::getUbicacion() const
{
    return ubicacion;
}

bool EventoCultural::getUsoCupon() const
{
    return usoCupon;
}

float EventoCultural::calcularCosto() const
{
    int cantidadTuristas = this->getTuristas().size();

    float costo = this->getPrecioBase() * cantidadTuristas;

    if (usoCupon)
    {
        costo = costo - (5 * cantidadTuristas);
    }

    return costo;
}