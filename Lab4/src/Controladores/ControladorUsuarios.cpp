#include "../../include/Controladores/ControladorUsuarios.h"
#include "../../include/Manejadores/ManejadorUsuarios.h"

ControladorUsuarios *ControladorUsuarios::instancia = nullptr;

ControladorUsuarios::ControladorUsuarios()
{
    nicknameMemoria = "";
    codigoMemoria = 0;
}

ControladorUsuarios *ControladorUsuarios::getInstance()
{
    if (instancia == nullptr)
    {
        instancia = new ControladorUsuarios();
    }
    return instancia;
}

bool ControladorUsuarios::altaPasajero(std::string nickname, std::string nombre,
                                       std::string contrasena, std::string email,
                                       std::string ci)
{
    return ManejadorUsuarios::getInstance()->nuevoPasajero(nickname, nombre,
                                                           contrasena, email, ci);
}

bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre,
                                        std::string contrasena, std::string email,
                                        std::set<TipoLibreta> libretas)
{
    return ManejadorUsuarios::getInstance()->nuevoConductor(nickname, nombre,
                                                            contrasena, email, libretas);
}

std::set<DTUsuario> ControladorUsuarios::listarUsuarios()
{
    return ManejadorUsuarios::getInstance()->listarUsuarios();
}

std::set<DTListarViaje> ControladorUsuarios::listarViajes()
{
    // TODO: requiere ManejadorViajes
    return std::set<DTListarViaje>();
}

std::set<std::string> ControladorUsuarios::listarPasajeros()
{
    std::set<std::string> resultado;
    for (DTUsuario dt : ManejadorUsuarios::getInstance()->listarPasajeros())
    {
        resultado.insert(dt.getNickname());
    }
    return resultado;
}

bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion)
{
    // TODO: requiere ManejadorViajes

    return false;
}

std::set<DTVehiculosConductor> ControladorUsuarios::listarVehiculosConductor(std::string nickname)
{
    // TODO: se le delega a conductor (?)

    return std::set<DTVehiculosConductor>();
}

int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula,
                                           int capacidad, std::string marca,
                                           std::string modelo, TipoVehiculo tipo)
{
    return ManejadorUsuarios::getInstance()->registrarVehiculo(nickname, matricula,
                                                               capacidad, marca, modelo, tipo);
}
