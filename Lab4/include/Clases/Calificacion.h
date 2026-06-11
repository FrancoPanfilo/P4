#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "../DTyENUM/DTFecha.h"

class Calificacion
{
private:
    DTFecha fecha;
    int puntaje;
    // vincular al usuario calificador
public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    int getPuntaje();
};

#endif
