#include "../h/DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

DTFecha::~DTFecha() {

};

int DTFecha::getAnio() const
{
    return this->anio;
}

int DTFecha::getMes() const
{
    return this->mes;
}

int DTFecha::getDia() const
{
    return this->dia;
}

string DTFecha::toString() const
{
    char buf[20];
    sprintf(buf, "%d/%d/%d", dia, mes, anio);
    return string(buf);
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
