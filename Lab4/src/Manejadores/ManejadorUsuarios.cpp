#include "../../include/Manejadores/ManejadorUsuarios.h"
#include "../../include/Manejadores/ManejadorVehiculos.h"

#include <iostream>

ManejadorUsuarios* ManejadorUsuarios::instancia = nullptr;

ManejadorUsuarios::ManejadorUsuarios() {}

ManejadorUsuarios* ManejadorUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorUsuarios();
    }
    return instancia;
}

bool ManejadorUsuarios::nuevoPasajero(std::string nickname,
                                       std::string nombre,
                                       std::string contrasena,
                                       std::string email,
                                       std::string ci) {

    if (contrasena.length() < 8) { return false; }

    bool e = usuarios.find(nickname) != usuarios.end();

    if (e) { return false; }

    Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);

    usuarios[nickname] = p;

    return true;
}

bool ManejadorUsuarios::nuevoConductor(std::string nickname,
                                        std::string nombre,
                                        std::string contrasena,
                                        std::string email,
                                        std::vector<TipoLibreta> libretas) {
    if (contrasena.length() < 8) { return false; }

    bool e = usuarios.find(nickname) != usuarios.end();

    if (e) { return false; }

    Conductor* c = new Conductor(nickname, nombre, contrasena, email, libretas);

    usuarios[nickname] = c;

    return true;

}

int ManejadorUsuarios::registrarVehiculo(std::string nickname,
                                          std::string matricula,
                                          int capacidad,
                                          std::string marca,
                                          std::string modelo,
                                          TipoVehiculo tipo) {

    Usuario* u = getUsuario(nickname);

    if (u == nullptr) {
        return -2; // No existe el usuario
    }

    Conductor* c = dynamic_cast<Conductor*>(u);

    if (c == nullptr) {
        return -2; // Existe usuario, pero no es conductor
    }

    ManejadorVehiculos* mv = ManejadorVehiculos::getInstance();

    if (mv->existeVehiculo(matricula)) { return -1; }

    bool tieneLibreta = c->tieneLibreta(tipo);

    if (!tieneLibreta) { return -2; }

    Vehiculo* v = mv->nuevoVehiculo(matricula, capacidad, marca, modelo, tipo);

    if (v == nullptr) { return -1; }

    c->agregarVehiculo(v);

    return 0;
}

std::vector<std::string> ManejadorUsuarios::listarPasajeros() {

  std::vector<std::string> resultado;

    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* u = it->second;

        Pasajero* p = dynamic_cast<Pasajero*>(u);

        if (p != nullptr) {
            resultado.push_back(p->getNickname());
        }
    }

    return resultado;
}

std::vector<DTUsuario> ManejadorUsuarios::listarUsuarios() {

    std::vector<DTUsuario> resultado;

    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* u = it->second;

        DTUsuario dt = u->getDTUsuario();

        resultado.push_back(dt);
    }

    return resultado;
}

/*
std::vector<DTUsuario> ManejadorUsuarios::listarUsuarios() {
    std::vector<DTUsuario> resultado;
    for (std::pair<std::string, Usuario*> par : usuarios) {
        Usuario* u = par.second;
        resultado.push_back(DTUsuario(u->getNickname(), u->getNombre()));
    }
    return resultado;
}
*/

Conductor* ManejadorUsuarios::findConductor(std::string nickname) {
    auto it = usuarios.find(nickname);

    if (it == usuarios.end()) { return nullptr; }

    Conductor* conductor = dynamic_cast<Conductor*>(it->second);

    return conductor;
}

Pasajero* ManejadorUsuarios::findPasajero(std::string nickname) {
    auto it = usuarios.find(nickname);

    if (it == usuarios.end()) { return nullptr; }

    Pasajero* pasajero = dynamic_cast<Pasajero*>(it->second);

    return pasajero;
}

Usuario* ManejadorUsuarios::getUsuario(std::string nickname) {
    auto it = usuarios.find(nickname);

    if (it == usuarios.end()) { return nullptr; }

    return it->second;
}

void ManejadorUsuarios::eliminarCalificacionesDeReserva(Reserva* reserva) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        it->second->quitarCalificacionesDeReserva(reserva);
    }
}

ManejadorUsuarios::~ManejadorUsuarios() {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}
