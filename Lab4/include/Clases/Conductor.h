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

class Conductor : public Usuario
{
private:
    std::vector<TipoLibreta> libretas;
    std::list<Vehiculo *> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs);
    ~Conductor();
    bool tieneLibreta(TipoVehiculo tipo);
    std::vector<DTVehiculosConductor> listarVehiculosConductor();
    std::vector<TipoLibreta> getLicencias();
    void agregarVehiculo(Vehiculo *v);
    bool hayViajesFechaConductor(DTFecha fecha);
    float getCalProm();
};

#endif
