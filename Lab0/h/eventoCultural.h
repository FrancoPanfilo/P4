#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include "experiencia.h"
#include <string>

using namespace std;

class EventoCultural : public Experiencia
{
private:
    string ubicacion;
    bool usoCupon;

public:
    EventoCultural(string codigoReserva,
                   string descripcion,
                   int precioBase,
                   DTFecha fecha,
                   string ubicacion,
                   bool usoCupon);
    ~EventoCultural();

    string getUbicacion() const;
    bool getUsoCupon() const;
    float calcularCosto() const;
};

#endif
