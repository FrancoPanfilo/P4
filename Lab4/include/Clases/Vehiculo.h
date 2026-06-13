#ifndef VEHICULO_H
#define VEHICULO_H

#include "../DTyENUM/TipoVehiculo.h"
#include "../DTyENUM/DTFecha.h"
#include <string>
#include <list>

class Viaje;
class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

    Conductor *conductor;
    std::list<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();

    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    std::string getNombreConductor();
    std::string getNicknameConductor();
    float getCalPromConductor();

    void setConductor(Conductor *conductor);
    void asociarViaje(Viaje* viaje);
    std::list<Viaje*> getViajes();

    void quitarViaje(Viaje* viaje);

    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
};

#endif
