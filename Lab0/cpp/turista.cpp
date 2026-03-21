#include "../h/turista.h"
#include <vector>
using namespace std;

Turista::Turista(const string &ci, const string &nombre, const string &email)
{
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}

Turista::~Turista() {

};

vector<string> Turista::listarExperiencias(DTFecha &desde, float min, float max) const
{
    vector<string> resultado;

    for (int i = 0; i < (int)experiencias.size(); i++)
    {
        Experiencia *exp = experiencias[i];
        DTFecha fechaExp = exp->getFecha();
        float costoExp = exp->calcularCosto();

        if (fechaExp > desde && costoExp >= min && costoExp <= max)
        {
            resultado.push_back(exp->getCodigoReserva());
        }
    }

    return resultado;
}

void Turista::agregarExperiencia(Experiencia *e)
{
    if (e != NULL)
    {
        experiencias.push_back(e);
    }
}

string Turista::toString() const
{
    return ci + "->" + nombre + "/" + email;
}
string Turista::getNombre() const
{
    return this->nombre;
}
string Turista::getEmail() const
{
    return this->email;
}
string Turista::getCi() const
{
    return this->ci;
}
void Turista::quitarExperiencia(string codigo)
{
    for (int i = 0; i < (int)this->experiencias.size(); i++)
    {
        if (this->experiencias[i]->getCodigoReserva() == codigo)
        {
            this->experiencias.erase(this->experiencias.begin() + i);
            break;
        }
    }
}

// retorna turista de vector que coincida ci,
/*
Turista* buscarPorCI(string ci)
{
    for (int i = 0; i < turistas.size(); i++)
    {
        if (turistas[i] != NULL && turistas[i]->getCi() == ci)
        {
            return turistas[i];
        }
    }
    return NULL;
}
*/