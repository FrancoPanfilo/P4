#include "../../include/Clases/Conductor.h"
#include "../../include/Clases/Vehiculo.h"
#include <algorithm>

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email)
{
    this->libretas = libs;
}

Conductor::~Conductor() {}

bool Conductor::tieneLibreta(TipoVehiculo tipo)
{
    TipoLibreta prof = (tipo == Auto) ? AutoProfesional : MotoProfesional;
    TipoLibreta amat = (tipo == Auto) ? AutoAmateur : MotoAmateur;
    return std::find(libretas.begin(), libretas.end(), prof) != libretas.end() ||
           std::find(libretas.begin(), libretas.end(), amat) != libretas.end();
}

void Conductor::agregarVehiculo(Vehiculo *v)
{
    this->vehiculos.push_back(v);
}

std::vector<TipoLibreta> Conductor::getLicencias()
{
    return libretas;
}

std::vector<DTVehiculosConductor> Conductor::listarVehiculosConductor()
{
    std::vector<DTVehiculosConductor> dtVehiculos;
    for (Vehiculo *v : vehiculos)
    {
        DTVehiculosConductor dtv(v->getMatricula(), v->getModelo(), v->getCapacidad());
        dtVehiculos.push_back(dtv);
    }
    return dtVehiculos;
}
