#ifndef RESERVA_H
#define RESERVA_H

#include "../DTyENUM/DTFecha.h"
class Pasajero;

class Reserva
{
private:
    int asientosReservados;
    DTFecha fecha;

    Pasajero *pasajero;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    int getAsientosReservados();
    DTFecha getFecha();

    Pasajero *getPasajero();
};

#endif
