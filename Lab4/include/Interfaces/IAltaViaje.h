#ifndef IALTA_VIAJE_H
#define IALTA_VIAJE_H

#include <set>
#include <string>

#include "../DTyENUM/DTVehiculosConductor.h"
#include "../DTyENUM/DTFecha.h"

class IAltaViaje {
public:        
    virtual std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname) = 0;    
    virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0;
    virtual ~IAltaViaje() {}
};

#endif