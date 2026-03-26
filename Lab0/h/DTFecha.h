#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>

using namespace std;

class DTFecha
{
private:
    int dia, mes, anio;

public:
    DTFecha(int, int, int);
    ~DTFecha();
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    string toString() const;
    bool operator>(const DTFecha &f) const; // para usar ">" con DTFecha
};

#endif