#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include "DTFecha.h"
#include "DTExpe.h"
#include "./turista.h"
#include <string>
#include <vector>

using namespace std;

class Turista; // declaración adelantada

class Experiencia
{
private:
    string codigoReserva;
    string descripcion;
    int precioBase;
    DTFecha fecha;
    vector<Turista *> turistas;

public:
    Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha);
    virtual ~Experiencia();
    void eliminarExperiencia();
    DTExpe getDT();
    virtual float calcularCosto() const = 0;
    string getCodigoReserva() const;
    string getDescripcion() const;
    int getPrecioBase() const;
    DTFecha getFecha() const;
    void agregarTurista(Turista *t); // agregar turista a experiencia
    vector<string> getTuristas() const;
};

#endif
