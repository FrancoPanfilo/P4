#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "../DTyENUM/DTFecha.h"

//---
class Usuario;
class Reserva;
//---

class Calificacion
{
private:
    DTFecha fecha;
    int puntaje;
    
    //---  vincular al usuario calificador
    Usuario* calificador;
    Reserva* reserva;
    //---

public:

    //---
    Calificacion(DTFecha fecha, int puntaje, Usuario* calificador, Reserva* reserva);
    //---

    ~Calificacion();

    int getPuntaje();

    //---    
    Usuario* getCalificador();
    DTFecha getFecha();
    Reserva* getReserva();
    //---

};

#endif
