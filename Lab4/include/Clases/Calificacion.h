#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "../DTyENUM/DTFecha.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    int getPuntaje();
};

#endif
