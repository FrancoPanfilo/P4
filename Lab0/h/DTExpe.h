#ifndef DTEXPE_H
#define DTEXPE_H

#include "DTFecha.h"

#include <string>
#include <ostream>
#include <iostream>
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
    // const
    DTExpe(string, string, DTFecha, vector<string>);

    // dest
    ~DTExpe();

    // getters
    string getCodigo() const;
    string getDesc() const;
    DTFecha getFecha() const;
    vector<string> getTuristas() const;

    string toString();
};

ostream &operator<<(ostream &os, const DTExpe &expe);

#endif