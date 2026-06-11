#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "../DTyENUM/TipoLibreta.h"
#include "../DTyENUM/TipoVehiculo.h"
#include "../DTyENUM/DTFecha.h"
#include "../DTyENUM/DTVehiculosConductor.h"
#include <vector>
#include <list>

class Vehiculo;

class Conductor : public Usuario {
private:
    std::vector<TipoLibreta> libretas;
    std::list<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs);
    ~Conductor();
    bool tieneLibreta(TipoLibreta tipo);
    DTVehiculo listarVehiculos();
    bool hayViajeFechaConductor(DTFecha fecha);
    std::vector<TipoLibreta> getLicencias();
};

#endif
