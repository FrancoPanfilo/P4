#ifndef DTEXPE_H
#define DTEXPE_H

#include <string>
#include "DTFecha.h"
#include <ostream>
#include <iostream>
class DTExpe
{
private:
    std::string codigo;
    std::string desc;
    DTFecha fecha;
    std::set<std::string> turistas;

public:
    // const
    DTExpe(std::string, std::string, DTFecha, std::set<std::string>);

    friend std::ostream &operator<<(std::ostream &os, const DTExpe &expe);

    // dest
    ~DTExpe();

    // getters
    std::string getCodigo();
    std::string getDesc();
    DTFecha getFecha();
    std::set<std::string> getTuristas();

    std::string toString();
};

#endif