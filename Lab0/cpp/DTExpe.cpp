#include "../h/DTExpe.h"
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const DTExpe &expe)
{
    os << expe.getCodigo() << " -> "
       << expe.getDesc() << " ("
       << expe.getFecha().toString() << ")";
    return os;
}

DTExpe::DTExpe(string codigo, string desc, DTFecha fecha, vector<string> turistas)
    : codigo(codigo), desc(desc), fecha(fecha), turistas(turistas)
{
}

DTExpe::~DTExpe() {

};

string DTExpe::getCodigo() const
{
    return this->codigo;
}

string DTExpe::getDesc() const
{
    return this->desc;
}

DTFecha DTExpe::getFecha() const
{
    return this->fecha;
}

vector<string> DTExpe::getTuristas() const
{
    return this->turistas;
}

// pasar set a String
string turistaString(vector<string> turistas)
{
    string turistaS;
    for (string turista : turistas)
    {
        turistaS += turista + ", ";
    }
    return turistaS;
}

string DTExpe::toString()
{
    string codigo = getCodigo();
    string descripcion = getDesc();
    DTFecha fecha = getFecha();
    string turista = turistaString(turistas);

    return codigo + "->" + descripcion + " (" + fecha.toString() + ") /" + turista;
}