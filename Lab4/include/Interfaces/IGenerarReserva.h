#ifndef IGENERAR_RESERVA_H
#define IGENERAR_RESERVA_H

#include <set>
#include <string>

#include "DTConsultaViaje.h"
#include "DTFecha.h"

class IGenerarReserva {
public:        
    virtual std::set<String> listarPasajeros() = 0;    
    virtual std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos)  = 0;
    virtual bool generarReserva(std::string nickname, int codigo, int asientos) = 0; 
    virtual ~IGenerarReserva() {}
};

#endif