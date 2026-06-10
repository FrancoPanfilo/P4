#include "../../include/Controladores/ControladorViajes.h"
#include "../../include/Manejadores/ManejadorUsuarios.h"
#include "../../include/DTyENUM/DTDetalleVehiculo.h"
#include "../../include/DTyENUM/DTDetalleReserva.h"
#include <vector>

ControladorViajes* ControladorViajes::instancia = nullptr;

ControladorViajes::ControladorViajes() {
    codigoMemoria = 0;
}

ControladorViajes* ControladorViajes::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorViajes();
    }
    return instancia;
}

std::set<DTVehiculosConductor> ControladorViajes::listarVehiculosConductor(std::string nickname) {
    return std::set<DTVehiculosConductor>();
}

bool ControladorViajes::altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                                  std::string destino, int asientos, float precio) {
    return false;
}

std::set<std::string> ControladorViajes::listarPasajeros() {
    return ManejadorUsuarios::getInstance()->listarPasajeros();
}

std::set<DTConsultaViaje> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen,
                                                             std::string destino, int asientos) {
    return std::set<DTConsultaViaje>();
}

bool ControladorViajes::generarReserva(std::string nickname, int codigo, int asientos) {
    return false;
}

std::set<DTListarViaje> ControladorViajes::listarViajes() {
    return std::set<DTListarViaje>();
}

DTDetalleViaje ControladorViajes::detalleViaje(int codigo) {
    codigoMemoria = codigo;
    DTDetalleVehiculo vehiculo("", 0, "", "", Auto);
    return DTDetalleViaje(0, DTFecha(1, 1, 2024), "", "", 0, 0.0f,
                          vehiculo, std::vector<DTDetalleReserva>());
}

void ControladorViajes::eliminarViaje() {
}

void ControladorViajes::cancelarEliminarViaje() {
}
