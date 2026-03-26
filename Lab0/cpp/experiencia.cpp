#include "../h/experiencia.h"

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
    for (int i = 0; i < (int)turistas.size(); i++)
    {
        nombres.push_back(turistas[i]->getNombre());
    }
    return DTExpe(this->codigoReserva, this->descripcion, this->fecha, nombres);
}

string Experiencia::getCodigoReserva() const
{
    return this->codigoReserva;
}

string Experiencia::getDescripcion() const
{
    return this->descripcion;
}

int Experiencia::getPrecioBase() const
{
    return this->precioBase;
}

DTFecha Experiencia::getFecha() const
{
    return this->fecha;
}

vector<string> Experiencia::getTuristas() const
{
    vector<string> nombres;
    for (int i = 0; i < (int)turistas.size(); i++)
    {
        nombres.push_back(turistas[i]->getNombre());
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
