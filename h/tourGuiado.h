#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include "experiencia.h"
#include <string>
#include <set>

class TourGuiado : public Experiencia
{
private:
    std::string agencia;
    std::set<std::string> lugaresVisitados;

public:
    TourGuiado(std::string codigoReserva,
               std::string descripcion,
               int precioBase,
               DTFecha fecha,
               std::string agencia,
               std::set<std::string> lugaresVisitados);
    ~TourGuiado();

    std::string getAgencia() const;
    std::set<std::string> getlugaresVisitados() const;

    float calcularCosto();
};

#endif
