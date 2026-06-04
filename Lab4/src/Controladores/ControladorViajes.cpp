#include "../../include/Controladores/ControladorViajes.h"

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

std::set<DTUsuarioViaje> ControladorViajes::listarUsuariosViaje(int codigo) {
    //TODO: usuarios del viaje (pasajeros con reserva + conductor); recordar codigo
    return std::set<DTUsuarioViaje>();
}

std::set<DTConsultaViaje> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen,
                                                             std::string destino, int asientos) {
    //TODO: viajes que cumplen criterio, ordenados por precioTotal asc y calificacion desc
    return std::set<DTConsultaViaje>();
}

bool ControladorViajes::generarReserva(std::string nickname, int codigo, int asientos) {
    //TODO: validar cupo y que el pasajero no tenga reserva en ese viaje; crear Reserva
    return false;
}

bool ControladorViajes::altaViaje(std::string matricula, DTFecha fecha, std::string origen,
                                  std::string destino, int asientos, float precio) {
    //TODO: validar capacidad >= asientos y que el conductor no tenga viaje en esa fecha; crear Viaje
    return false;
}

DTDetalleViaje ControladorViajes::detalleViaje(int codigo) {
    codigoMemoria = codigo; // recordar codigo en memoria
    //TODO: armar el detalle real del viaje (vehiculo + reservas)
    DTDetalleVehiculo vehiculo("", 0, "", "", Auto);
    return DTDetalleViaje(0, DTFecha(1, 1, 2024), "", "", 0, 0.0f,
                          vehiculo, std::vector<DTDetalleReserva>());
}

void ControladorViajes::eliminarViaje() {
    //TODO: eliminar viaje (codigoMemoria) en cascada (reservas + calificaciones); liberar memoria
}

void ControladorViajes::cancelarEliminarViaje() {
    //TODO: liberar memoria (codigoMemoria)
}
