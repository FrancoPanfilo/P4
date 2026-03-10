
#include "../h/DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

DTFecha::~DTFecha() {

};

int DTFecha::getAnio()
{
    return this->anio;
}

int DTFecha::getMes()
{
    return this->mes;
}

int DTFecha::getDia()
{
    return this->dia;
}

std::string DTFecha::toString() const
{
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

// para usar ">" con DTFecha
bool DTFecha::operator>(const DTFecha &f) const
{
    if (anio != f.anio)
        return anio > f.anio;
    if (mes != f.mes)
        return mes > f.mes;
    return dia > f.dia;
}