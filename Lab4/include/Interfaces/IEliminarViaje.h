#ifndef IELIMINAR_VIAJE_H
#define IELIMINAR_VIAJE_H

#include <vector>

#include "../DTyENUM/DTListarViaje.h"
#include "../DTyENUM/DTDetalleViaje.h"

class IEliminarViaje {
public:        
    virtual std::vector<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
    virtual ~IEliminarViaje() {}
};

#endif