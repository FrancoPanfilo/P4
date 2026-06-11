#ifndef CONTROLADOR_VIAJES_H
#define CONTROLADOR_VIAJES_H

#include "../Interfaces/IAltaViaje.h"
#include "../Interfaces/IGenerarReserva.h"
#include "../Interfaces/IEliminarViaje.h"
#include <vector>
class ControladorViajes : public IAltaViaje, public IGenerarReserva, public IEliminarViaje
{
private:
    static ControladorViajes *instancia;

    int codigoMemoria;

    ControladorViajes();

public:
    static ControladorViajes *getInstance();

    std::vector<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                   std::string destino, int asientos, float precio);

    std::vector<std::string> listarPasajeros();
    std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen,
                                                 std::string destino, int asientos);
    bool generarReserva(std::string nickname, int codigo, int asientos);

    std::vector<DTListarViaje> listarViajes();
    DTDetalleViaje detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif
