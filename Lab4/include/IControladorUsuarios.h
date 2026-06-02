#ifndef ICONTROLADOR_USUARIOS_H
#define ICONTROLADOR_USUARIOS_H

#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include <string>
#include <set>
#include <list>

class IControladorUsuarios {
public:
    virtual ~IControladorUsuarios() {}

    virtual bool altaPasajero(std::string nickname, std::string nombre,
                              std::string contrasena, std::string email,
                              std::string ci) = 0;

    virtual bool altaConductor(std::string nickname, std::string nombre,
                               std::string contrasena, std::string email,
                               std::set<TipoLibreta> libretas) = 0;

    virtual int registrarVehiculo(std::string nickname, std::string matricula,
                                  int capacidad, std::string marca,
                                  std::string modelo, TipoVehiculo tipo) = 0;

    virtual std::list<DTUsuario> listarUsuarios() = 0;

    virtual std::list<DTListarViaje> listarViajes(std::string nickname) = 0;

    virtual std::set<std::string> listarPasajeros() = 0;

    virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;
};

#endif
