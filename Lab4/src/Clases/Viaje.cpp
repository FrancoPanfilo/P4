#include "../../include/Clases/Viaje.h"
#include "../../include/Clases/Vehiculo.h"
#include "../../include/Clases/Reserva.h"
#include "../../include/Clases/Pasajero.h"

int Viaje::ultimoCodigo = 0;

Viaje::Viaje(Vehiculo *vehiculo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio)
{
    this->codigo = ++ultimoCodigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = vehiculo;
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

// ¿Dónde se usa?
std::vector<DTDetalleReserva> Viaje::getDTReservas()
{
    std::vector<DTDetalleReserva> dtReservas;
    for (Reserva *r : reservas)
    {
        DTDetalleReserva dtr(r->getAsientosReservados(), r->getFecha(), r->getPasajero()->getNickname());
        dtReservas.push_back(dtr);
    }
    return dtReservas;
}

std::vector<Reserva*> Viaje::getReservas()
{
    return reservas;
}

Vehiculo* Viaje::getVehiculo(){
    return vehiculo;
}

DTDetalleVehiculo Viaje::getDTVehiculo()
{
    return DTDetalleVehiculo(vehiculo->getMatricula(), vehiculo->getCapacidad(), vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getTipo());
}

DTListarViaje Viaje::getDTListarViaje() {
   
    return DTListarViaje(
        this->codigo,
        this->fecha,
        this->origen,
        this->destino,
        this->vehiculo->getNicknameConductor()
    );
}

DTDetalleViaje Viaje::getDTDetalleViaje() {
    DTDetalleVehiculo dtVehiculo(
        this->vehiculo->getMatricula(),
        this->vehiculo->getCapacidad(),
        this->vehiculo->getMarca(),
        this->vehiculo->getModelo(),
        this->vehiculo->getTipo()
    );

    std::vector<DTDetalleReserva> dtReservas;

    for (Reserva* r : this->reservas) {
        Pasajero* p = r->getPasajero();

        DTDetalleReserva dtReserva(
            r->getAsientosReservados(),
            r->getFecha(),
            p->getNickname()
        );

        dtReservas.push_back(dtReserva);
    }

    return DTDetalleViaje(
        this->codigo,
        this->fecha,
        this->origen,
        this->destino,
        this->asientosPublicados,
        this->precio,
        dtVehiculo,
        dtReservas
    );
}

void Viaje::vaciarReservas() {
    reservas.clear();
}

bool Viaje::cumpleCriterio(DTFecha fecha, std::string origen, std::string destino, int asientos)
{
    int reservados = 0;
    for (Reserva *r : reservas)
    {
        reservados += r->getAsientosReservados();
    }

    return reservados + asientos <= asientosPublicados &&
           this->fecha == fecha &&
           this->origen == origen &&
           this->destino == destino;
}

DTConsultaViaje Viaje::getDTConsultaViaje(int asientos)
{
    return DTConsultaViaje(codigo,
                           vehiculo->getMarca(),
                           vehiculo->getModelo(),
                           vehiculo->getNombreConductor(),
                           vehiculo->getCalPromConductor(),
                           precio * asientos);
}

bool Viaje::puedeReservar(int asientos)
{
    int reservados = 0;
    for (Reserva *r : reservas)
    {
        reservados += r->getAsientosReservados();
    }

    return reservados + asientos <= asientosPublicados;
}
