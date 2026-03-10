#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include "experiencia.h"
#include <string>

class EventoCultural : public Experiencia
{
private:
    std::string ubicacion;
    bool usoCupon;

public:
    EventoCultural(std::string codigoReserva,
                   std::string descripcion,
                   int precioBase,
                   DTFecha fecha,
                   std::string ubicacion,
                   bool usoCupon);
    ~EventoCultural();

    std::string getUbicacion() const;
    bool getUsoCupon() const;

    float calcularCosto() const;
};

#endif
