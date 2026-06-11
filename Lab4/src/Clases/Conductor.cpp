#include "../../include/Clases/Conductor.h"
#include "../../include/Clases/Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::vector<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

bool Conductor::tieneLibreta(TipoVehiculo tipo) {
    if (tipo == Auto) {
        return std::find(libretas.begin(), libretas.end(), AutoProfesional) != libretas.end() || std::find(libretas.begin(), libretas.end(), AutoAmateur) != libretas.end();
    }
    return libretas.count(MotoProfesional) > 0 || libretas.count(MotoAmateur) > 0;
}

void Conductor::agregarVehiculo(Vehiculo* v) {
    vehiculos.push_back(v);
}

std::vector<TipoLibreta> Conductor::getLicencias() {
    return libretas;
}

bool Conductor::hayViajeFechaConductor(DTFecha fecha){
    for(it=vehiculos.begin(); it!=vehiculos.end(); ++it){
        for(iv=it->viajes.begin(); iv!=it->viajes.end(); ++iv){
            if (iv->fecha == fecha){
                return true;
            }
        }
    }
    return false;
}

std::set<DTVehiculosConductor> Conductor::listarVehiculos() { 
    std::set<DTVehiculosConductor> dtveh;
    DTVehiculoConductor veh;
    for (it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        veh = DTVehiculoConductor(it->getMatricula(), it->getModelo(), it->getCapacidad());
        dtveh.insert(veh);
    }
    return dtveh;
}
