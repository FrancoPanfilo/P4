#ifndef CONTROLADOR_VIAJES_H
#define CONTROLADOR_VIAJES_H

#include "../Interfaces/IAltaViaje.h"
#include "../Interfaces/IGenerarReserva.h"
#include "../Interfaces/IEliminarViaje.h"

class ControladorViajes : public IAltaViaje, public IGenerarReserva, public IEliminarViaje {
private:
    static ControladorViajes* instancia;

    int codigoMemoria;

    ControladorViajes();

public:
    static ControladorViajes* getInstance();

    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                   std::string destino, int asientos, float precio);

    std::set<std::string> listarPasajeros();
    std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen,
                                              std::string destino, int asientos);
    bool generarReserva(std::string nickname, int codigo, int asientos);

    std::set<DTListarViaje> listarViajes();
    DTDetalleViaje detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif
