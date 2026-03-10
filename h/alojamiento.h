#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "experiencia.h"
#include <string>
#include "TipoRegimen.h"
class Alojamiento : public Experiencia
{
private:
    string hotel;
    TipoRegimen regimen;
    int cantidadNoches;

public:
    Alojamiento(std::string codigoReserva, std::string nombre, double precio,
                std::string hotel, TipoRegimen regimen, int cantidadNoches);
    ~Alojamiento();
    float calcularCosto();
    int getCantNoches();
};

#endif
