#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "../DTyENUM/TipoLibreta.h"
#include "../DTyENUM/TipoVehiculo.h"
#include "../DTyENUM/DTFecha.h"
#include "../DTyENUM/DTVehiculosConductor.h"
#include <set>
#include <list>

class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::list<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();
    bool tieneLibreta(TipoLibreta tipo);
    DTVehiculo listarVehiculos();
    bool hayViajeFechaConductor(DTFecha fecha);
    set<TipoLibreta> getLicencias();
};

#endif
