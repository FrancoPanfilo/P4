
#include "../h/tourGuiado.h"
#include <iostream>

TourGuiado::TourGuiado(std::string codigoReserva,
                       std::string descripcion,
                       int precioBase,
                       DTFecha fecha,
                       std::string agencia,
                       std::set<std::string> lugaresVisitados)
    : Experiencia(codigoReserva, descripcion, precioBase, fecha){
          this->agencia = agencia this->lugaresVisitados = lugaresVisitados} TourGuiado::~TourGuiado() {}

std::string TourGuiado::getAgencia() const
{
    return agencia;
}

std::set<std::string> TourGuiado::getlugaresVisitados() const
{
    return lugaresVisitados;
}

float TourGuiado::calcularCosto() const
{
    int cantidadLugares = lugaresVisitados.size();
    int cantidadTuristas = turistas.size();

    return precioBase + 2 * cantidadLugares * cantidadTuristas;
}
