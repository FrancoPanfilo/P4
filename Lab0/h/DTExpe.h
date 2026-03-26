#ifndef DTEXPE_H
#define DTEXPE_H

#include "DTFecha.h"

#include <string>
#include <ostream>
#include <vector>
using namespace std;

class DTExpe
{
private:
    string codigo;
    string desc;
    DTFecha fecha;
    vector<string> turistas;

public:
    DTExpe(string, string, DTFecha, vector<string>);
    ~DTExpe();
    string getCodigo() const;
    string getDesc() const;
    DTFecha getFecha() const;
    vector<string> getTuristas() const;
    string toString() const;
};

ostream &operator<<(ostream &os, const DTExpe &expe);

#endif