#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include "experiencia.h"
#include <string>

using namespace std;

class TourGuiado : public Experiencia
{
private:
    string agencia;
    vector<string> lugaresVisitados;

public:
    TourGuiado(string codigoReserva,
               string descripcion,
               int precioBase,
               DTFecha fecha,
               string agencia,
               vector<string> lugaresVisitados);
    ~TourGuiado();

    string getAgencia() const;
    vector<string> getlugaresVisitados() const;

    float calcularCosto() const;
};

#endif
