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

std::vector<DTVehiculosConductor> ControladorViajes::listarVehiculosConductor(std::string nickname) {
    return std::vector<DTVehiculosConductor>();
}

bool ControladorViajes::altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                                  std::string destino, int asientos, float precio) {
    return false;
}

std::vector<std::string> ControladorViajes::listarPasajeros() {
    return ManejadorUsuarios::getInstance()->listarPasajeros();
}

std::vector<DTConsultaViaje> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen,
                                                             std::string destino, int asientos) {
    return std::vector<DTConsultaViaje>();
}

bool ControladorViajes::generarReserva(std::string nickname, int codigo, int asientos) {
    return false;
}

std::vector<DTListarViaje> ControladorViajes::listarViajes() {
    return std::vector<DTListarViaje>();
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
