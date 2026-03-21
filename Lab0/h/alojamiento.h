#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "experiencia.h"
#include <string>
#include "TipoRegimen.h"

using namespace std;

class Alojamiento : public Experiencia
{
private:
    string hotel;
    TipoRegimen regimen;
    int cantidadNoches;

public:
    Alojamiento(string codigoReserva, string descripcion, int precio, DTFecha fecha,
                string hotel, TipoRegimen regimen, int cantidadNoches);
    ~Alojamiento();

    float calcularCosto() const override;

    int getCantNoches() const;
};

#endif
