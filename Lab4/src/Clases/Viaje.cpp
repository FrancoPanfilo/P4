#include "../../include/Clases/Viaje.h"
#include "../../include/Clases/Vehiculo.h"
#include "../../include/Clases/Reserva.h"
#include "../../include/Clases/Pasajero.h"

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

DTFecha Viaje::getFecha()
{
    return this->fecha;
}

int Viaje::obtenerCodigo()
{
    return this->codigo;
}

void Viaje::agregarReserva(Reserva *reserva)
{
    this->reservas.push_back(reserva);
}

std::vector<DTDetalleReserva> Viaje::getReservas()
{
    std::vector<DTDetalleReserva> dtReservas;
    for (Reserva *r : reservas)
    {
        DTDetalleReserva dtr(r->getAsientosReservados(), r->getFecha(), r->getPasajero()->getNickname());
        dtReservas.push_back(dtr);
    }
    return dtReservas;
}

DTDetalleVehiculo Viaje::getVehiculo()
{
    return DTDetalleVehiculo(vehiculo->getMatricula(), vehiculo->getCapacidad(),
                             vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getTipo());
}

bool Viaje::cumpleCriterio(DTFecha fecha, std::string origen, std::string destino, int asientos)
{
    return false;
}

DTConsultaViaje Viaje::getDTConsultaViaje(int asientos)
{
    return DTConsultaViaje(0, "", "", "", 0.0f, 0.0f);
}
