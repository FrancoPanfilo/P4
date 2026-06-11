#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H

#include "../Interfaces/IAltaUsuario.h"
#include "../Interfaces/ICalificarUsuario.h"

class ControladorUsuarios : public IAltaUsuario, public ICalificarUsuario {
private:
    static ControladorUsuarios* instancia;

    std::string nicknameMemoria;
    int codigoMemoria;

    ControladorUsuarios();

public:
    static ControladorUsuarios* getInstance();

    bool altaPasajero(std::string nickname, std::string nombre,
                      std::string contrasena, std::string email,
                      std::string ci);
    bool altaConductor(std::string nickname, std::string nombre,
                       std::string contrasena, std::string email,
                       std::vector<TipoLibreta> libretas);
    int registrarVehiculo(std::string nickname, std::string matricula,
                          int capacidad, std::string marca,
                          std::string modelo, TipoVehiculo tipo);

    std::vector<DTUsuario> listarUsuarios();
    std::vector<DTListarViaje> listarViajes(std::string nickname);
    std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo);
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);
};

#endif
