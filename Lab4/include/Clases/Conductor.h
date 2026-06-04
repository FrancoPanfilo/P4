#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "./DTyENUM/TipoLibreta.h"
#include <set>

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();
    bool tieneLibreta(TipoLibreta tipo);
    DTVehiculo listarVehiculos();
    bool hayViajeFechaConductor(DTFecha fecha);
    set<TipoLibreta> getLicencias();
};

#endif
