#include "../h/experiencia.h"
#include "../h/DTExpe.h"

#include <iostream>
#include <vector>

using namespace std;

Experiencia::Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha)
    : codigoReserva(codigoReserva),
      descripcion(descripcion),
      precioBase(precioBase),
      fecha(fecha) {}

Experiencia::~Experiencia() {}

DTExpe Experiencia::getDT()
{
    vector<string> nombres;
    for (Turista *t : this->turistas)
    {
        nombres.push_back(t->getNombre());
    }
    return DTExpe(this->codigoReserva, this->descripcion, this->fecha, nombres);
}

string Experiencia::getCodigoReserva()
{
    return this->codigoReserva;
}

string Experiencia::getDescripcion()
{
    return this->descripcion;
}

int Experiencia::getPrecioBase() const
{
    return this->precioBase;
}

DTFecha Experiencia::getFecha()
{
    return this->fecha;
}

vector<string> Experiencia::getTuristas() const
{
    vector<string> nombres;
    for (Turista *t : this->turistas)
    {
        nombres.push_back(t->getNombre());
    }
    return nombres;
}

void Experiencia::agregarTurista(Turista *t)
{
    if (t != NULL)
    {
        this->turistas.push_back(t);
    }
}

void Experiencia::eliminarExperiencia()
{

    vector<Turista *> turistas = this->turistas;
    for (int i = 0; i < (int)turistas.size(); i++)
    {
        if (turistas[i] != NULL)
        {
            turistas[i]->quitarExperiencia(this->codigoReserva);
        }
    }
    delete this;

    return; // fin
}

/*
//retorna exp de vector que coincida codigo
Experiencia* buscarPorCodigo(string codigo)
{
    for (int i = 0; i < experiencias.size(); i++)
    {
        if (experiencias[i] != NULL && experiencias[i]->getCodigoReserva() == codigo)
        {
            return experiencias[i];
        }
    }
    return NULL;
}
*/