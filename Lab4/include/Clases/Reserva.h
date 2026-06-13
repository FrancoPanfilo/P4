#ifndef RESERVA_H
#define RESERVA_H

//--
#include <string>
#include "Pasajero.h"
//--
#include "../DTyENUM/DTFecha.h"

//--
class Viaje;
//--

class Pasajero;

class Reserva
{
private:
    int asientosReservados;
    DTFecha fecha;

    // reserva tiene pasajero y viaje
    Pasajero *pasajero;
    //-- 
    Viaje* viaje;
    //-- 

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    int getAsientosReservados();
    DTFecha getFecha();
    Pasajero *getPasajero();
    Viaje* getViaje();

    void setPasajero(Pasajero *pasajero);
    void setViaje(Viaje* viaje);

    //--    
    bool reservaEsDeUsuario(std::string nickname);      
    //--
};

#endif
