#ifndef IGENERAR_RESERVA_H
#define IGENERAR_RESERVA_H

#include <vector>
#include <string>

#include "../DTyENUM/DTConsultaViaje.h"
#include "../DTyENUM/DTFecha.h"

class IGenerarReserva {
public:        
    virtual std::vector<std::string> listarPasajeros() = 0;    
    virtual std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos)  = 0;
    virtual bool generarReserva(std::string nickname, int codigo, int asientos) = 0; 
    virtual ~IGenerarReserva() {}
};

#endif