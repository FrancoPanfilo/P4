#ifndef CONTROLADOR_VIAJES_H
#define CONTROLADOR_VIAJES_H

#include <string>
#include <set>

#include "../DTyENUM/DTUsuarioViaje.h"
#include "../DTyENUM/DTConsultaViaje.h"
#include "../DTyENUM/DTDetalleViaje.h"
#include "../DTyENUM/DTFecha.h"

// NOTA: la herencia de interfaces se agregara cuando las interfaces se
// regrupen para coincidir con las cajas del DCD ("bien implementadas").

class ControladorViajes {
private:
    static ControladorViajes* instancia;

    // Memoria del caso de uso "Eliminar Viaje" (CU con memoria)
    int codigoMemoria;

    ControladorViajes();

public:
    static ControladorViajes* getInstance();

    std::set<DTUsuarioViaje> listarUsuariosViaje(int codigo);
    std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen,
                                              std::string destino, int asientos);
    bool generarReserva(std::string nickname, int codigo, int asientos);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                   std::string destino, int asientos, float precio);
    DTDetalleViaje detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif
