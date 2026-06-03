#ifndef RESERVA_H
#define RESERVA_H

#include "../DTyENUM/DTFecha.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
};

#endif
