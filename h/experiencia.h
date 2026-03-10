#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H
#include "DTFecha.h"
#include "turista.h"
#include "DTExpe.h"
#include <iostream>
#include <list>

class Experiencia
{
private:
    std::string codigoReserva;
    std::string descripcion;
    int precioBase;
    DTFecha fecha;
    std::list<Turista *> turistas;

public:
    DTExpe getDT();
    virtual float calcularCosto() = 0;
    std::string getCodigoReserva();
    std::string getDescripcion();
    int getPrecioBase();
    DTFecha getFecha();
    std::list<string> getTuristas();
};

#endif
