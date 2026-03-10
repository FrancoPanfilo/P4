#include "../h/DTExpe.h"
#include <set>

std::ostream &operator<<(std::ostream &os, const DTExpe &expe)
{
    os << expe.codigo << " -> "
       << expe.desc << " ("
       << expe.fecha.toString() << ")";
    return os;
}

DTExpe::DTExpe(std::string codigo, std::string desc, DTFecha fecha, std::set<std::string> turistas)
    : codigo(codigo), desc(desc), fecha(fecha), turistas(turistas)
{
}

DTExpe::~DTExpe() {

};

string DTExpe::getCodigo()
{
    return this->codigo;
}

string DTExpe::getDesc()
{
    return this->desc;
}

DTFecha DTExpe::getFecha()
{
    return this->fecha;
}

set<string> DTExpe::getTuristas()
{
    return this->turistas;
}

// pasar set a String
std::string turistaString(set<std::string> turistas)
{
    string turistaS;
    for (string turista : turistas)
    {
        turistaS += turista + ", ";
    }
    return turistaS;
}

std::string DTExpe::toString()
{
    std::string codigo = getCodigo();
    string descripcion = getDesc();
    DTFecha fecha = getFecha();
    string turista = turistaString(turistas);

    return codigo + "->" + descripcion + " (" + fecha.toString() + ") /" + turista;
}