#include "../../include/Controladores/ControladorUsuarios.h"
#include "../../include/Manejadores/ManejadorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::instancia = nullptr;

ControladorUsuarios::ControladorUsuarios() {
    nicknameMemoria = "";
    codigoMemoria = 0;
}

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuarios();
    }
    return instancia;
}

bool ControladorUsuarios::altaPasajero(std::string nickname, std::string nombre,
                                       std::string contrasena, std::string email,
                                       std::string ci) {
    return ManejadorUsuarios::getInstance()->nuevoPasajero(nickname, nombre,
                                                           contrasena, email, ci);
}

bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre,
                                        std::string contrasena, std::string email,
                                        std::vector<TipoLibreta> libretas) {
    return ManejadorUsuarios::getInstance()->nuevoConductor(nickname, nombre,
                                                            contrasena, email, libretas);
}

int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula,
                                           int capacidad, std::string marca,
                                           std::string modelo, TipoVehiculo tipo) {
    return ManejadorUsuarios::getInstance()->registrarVehiculo(nickname, matricula,
                                                               capacidad, marca, modelo, tipo);
}

std::vector<DTUsuario> ControladorUsuarios::listarUsuarios() {
    return ManejadorUsuarios::getInstance()->listarUsuarios();
}

std::vector<DTListarViaje> ControladorUsuarios::listarViajes(std::string nickname) {
    return std::vector<DTListarViaje>();
}

std::vector<DTUsuarioViaje> ControladorUsuarios::listarUsuariosViaje(int codigo) {
    return std::vector<DTUsuarioViaje>();
}

bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    return false;
}
