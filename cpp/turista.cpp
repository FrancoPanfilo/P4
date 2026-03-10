#include "../h/turista.h"

using namespace std;

Turista::Turista(string ci, string nombre, string email)
{
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}

Turista::~Turista() {

};

set<string> Turista::listarExperiencias(DTFecha desde, float min, float max)
{
    set<string> resultado;

    for (set<Experiencia *>::iterator it = experiencias.begin(); it != experiencias.end(); ++it)
    {
        Experiencia *exp = *it;

        if (exp != NULL)
        {
            DTFecha fechaExp = exp->getFecha();
            float costoExp = exp->calcularCosto();

            if (fechaExp > desde && costoExp >= min && costoExp <= max)
            {
                resultado.insert(exp->getCodigoReserva());
            }
        }
    }

    return resultado;
}

void Turista::agregarExperiencia(Experiencia *e)
{
    if (e != NULL)
    {
        experiencias.insert(e);
    }
}

string Turista::toString()
{
    return ci + "->" + nombre + "/" + email;
}
std::string Turista::getNombre()
{
    return this->nombre;
}
std::string Turista::getEmail()
{
    return this->email;
}
std::string Turista::getCi()
{
    return this->ci;
}