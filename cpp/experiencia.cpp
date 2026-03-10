#include "../h/experiencia.h"
#include <iostream>
#include "../h/DTExpe.h"
DTExpe Experiencia::getDT()
{
    std::set<std::string> nombres;
    for (Turista *t : this->turistas)
    {
        nombres.insert(t->getNombre());
    }
    return DTExpe(this->codigoReserva, this->descripcion, this->fecha, nombres);
}
std::string Experiencia::getCodigoReserva()
{
    return this->codigoReserva;
}
std::string Experiencia::getDescripcion()
{
    return this->descripcion;
}
int Experiencia::getPrecioBase()
{
    return this->precioBase;
}

DTFecha Experiencia::getFecha()
{
    return this->fecha;
}
std::list<string> Experiencia::getTuristas()
{
    std::list<string> nombres;
    for (Turista *t : this->turistas)
    {
        nombres.push_back(t->getNombre());
    }
    return nombres;
}