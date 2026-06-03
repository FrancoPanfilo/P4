#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H

#include <string>
#include <set>

#include "../DTyENUM/DTUsuario.h"
#include "../DTyENUM/DTListarViaje.h"
#include "../DTyENUM/DTVehiculosConductor.h"
#include "../DTyENUM/TipoLibreta.h"
#include "../DTyENUM/TipoVehiculo.h"

// NOTA: la herencia de interfaces se agregara cuando las interfaces se
// regrupen para coincidir con las cajas del DCD ("bien implementadas").

class ControladorUsuarios {
private:
    static ControladorUsuarios* instancia;

    // Memoria del caso de uso "Calificar Usuario" (CU con memoria)
    std::string nicknameMemoria;
    int codigoMemoria;

    ControladorUsuarios();

public:
    static ControladorUsuarios* getInstance();

    bool altaPasajero(std::string nickname, std::string nombre,
                      std::string contrasena, std::string email,
                      std::string ci);
    bool altaConductor(std::string nickname, std::string nombre,
                       std::string contrasena, std::string email,
                       std::set<TipoLibreta> libretas);
    std::set<DTUsuario> listarUsuarios();
    std::set<DTListarViaje> listarViajes();
    std::set<std::string> listarPasajeros();
    bool calificarUsuario(std::string nicknameCalificado, int calificacion);
    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
    int registrarVehiculo(std::string nickname, std::string matricula,
                          int capacidad, std::string marca,
                          std::string modelo, TipoVehiculo tipo);
};

#endif
