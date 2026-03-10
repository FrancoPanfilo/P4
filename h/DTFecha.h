#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>

using namespace std;

class DTFecha
{
private:
    int dia, mes, anio;

public:
    // const
    DTFecha(int, int, int);

    // dest
    ~DTFecha();

    // getters
    int getDia();
    int getMes();
    int getAnio();

    string toString() const;

    bool operator>(const DTFecha &f) const; // para usar ">" con DTFecha
};

#endif