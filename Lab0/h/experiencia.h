#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include "DTFecha.h"
#include "turista.h"
#include "DTExpe.h"

#include <iostream>
#include <string>
#include <list>
#include <set>
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

    string getCodigoReserva();
    string getDescripcion();
    int getPrecioBase() const;
    DTFecha getFecha();

    void agregarTurista(Turista *t); // agregar turista a experiencia

    Experiencia *buscarPorCodigo(string codigo);

    vector<string> getTuristas() const;
};

#endif
