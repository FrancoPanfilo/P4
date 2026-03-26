#include "../h/DTExpe.h"

using namespace std;
string turistaString(vector<string> turistas)
{
    string turistaS;
    for (int i = 0; i < (int)turistas.size(); i++)
    {
        turistaS += turistas[i] + "   ";
    }
    return turistaS;
}
ostream &operator<<(ostream &os, const DTExpe &expe)
{

    os << expe.getCodigo() << "->"
       << expe.getDesc() << "("
       << expe.getFecha().toString() << ")/"
       << turistaString(expe.getTuristas())
       << endl;
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
