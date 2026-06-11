#ifndef IALTA_USUARIO_H
#define IALTA_USUARIO_H

#include <string>
#include <vector>

#include "../DTyENUM/TipoVehiculo.h"
#include "../DTyENUM/TipoLibreta.h"

class IAltaUsuario {
public:        
    virtual bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;    
    virtual bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libretas) = 0;
    virtual int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) = 0;
    virtual ~IAltaUsuario() {}
};

#endif