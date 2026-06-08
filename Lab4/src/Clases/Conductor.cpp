#include "../../include/Clases/Conductor.h"
#include "../../include/Clases/Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

bool Conductor::tieneLibreta(TipoVehiculo tipo) {
    if (tipo == Auto) {
        return libretas.count(AutoProfesional) > 0 || libretas.count(AutoAmateur) > 0;
    }
    return libretas.count(MotoProfesional) > 0 || libretas.count(MotoAmateur) > 0;
}

void Conductor::agregarVehiculo(Vehiculo* v) {
    vehiculos.push_back(v);
}

std::set<TipoLibreta> Conductor::getLicencias() {
    return libretas;
}
