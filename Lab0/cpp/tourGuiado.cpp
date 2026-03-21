
#include "../h/tourGuiado.h"
#include <iostream>

using namespace std;

TourGuiado::TourGuiado(string codigoReserva,
                       string descripcion,
                       int precioBase,
                       DTFecha fecha,
                       string agencia,
                       vector<string> lugaresVisitados)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha)
{
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
}

TourGuiado::~TourGuiado() {}

string TourGuiado::getAgencia() const
{
    return agencia;
}

vector<string> TourGuiado::getlugaresVisitados() const
{
    return lugaresVisitados;
}

float TourGuiado::calcularCosto() const
{
    int cantidadLugares = lugaresVisitados.size();
    int cantidadTuristas = this->getTuristas().size();

    return this->getPrecioBase() + 2 * cantidadLugares * cantidadTuristas;
}
