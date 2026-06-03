
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
    // Verifico si ya existe un usuario con ese nickname
    if (usuarios.find(nickname) != usuarios.end()) {
        return false;
    }

    Pasajero* pasajero = new Pasajero(nickname, nombre, contrasena, email, ci);

    usuarios[nickname] = pasajero;

    return true;
}

bool ManejadorUsuarios::nuevoConductor(std::string nickname,
                                        std::string nombre,
                                        std::string contrasena,
                                        std::string email,
                                        std::set<TipoLibreta> libretas) {
    // Verifico si ya existe un usuario con ese nickname
    if (usuarios.find(nickname) != usuarios.end()) {
        return false;
    }

    Conductor* conductor = new Conductor(nickname, nombre, contrasena, email, libretas);

    usuarios[nickname] = conductor;

    return true;
}

int ManejadorUsuarios::registrarVehiculo(std::string nickname,
                                          std::string matricula,
                                          int capacidad,
                                          std::string marca,
                                          std::string modelo,
                                          TipoVehiculo tipo) {
    // Busco el conductor
    Usuario* usuario = getUsuario(nickname);

    if (usuario == nullptr) {
        return 0; // no existe usuario
    }

    Conductor* conductor = dynamic_cast<Conductor*>(usuario);

    if (conductor == nullptr) {
        return 1; // existe usuario, pero no es conductor
    }

    ManejadorVehiculos* mv = ManejadorVehiculos::getInstance();

    // Esta operación depende de cómo tengas definido ManejadorVehiculos
    // Ejemplo posible:
    bool ok = mv->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipo);

    if (!ok) {
        return 2; // matrícula ya existente u otro error
    }

    return 3; // vehículo registrado correctamente
}

std::set<DTUsuario> ManejadorUsuarios::listarPasajeros() {
    std::set<DTUsuario> resultado;

    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* usuario = it->second;

        Pasajero* pasajero = dynamic_cast<Pasajero*>(usuario);

        if (pasajero != nullptr) {
            DTUsuario dt(
                pasajero->getNickname(),
                pasajero->getNombre(),
                pasajero->getEmail()
            );

            resultado.insert(dt);
        }
    }

    return resultado;
}

Pasajero* ManejadorUsuarios::findPasajero(std::string nickname) {
    auto it = usuarios.find(nickname);

    if (it == usuarios.end()) {
        return nullptr;
    }

    Pasajero* pasajero = dynamic_cast<Pasajero*>(it->second);

    return pasajero;
}

Usuario* ManejadorUsuarios::getUsuario(std::string nickname) {
    auto it = usuarios.find(nickname);

    if (it == usuarios.end()) {
        return nullptr;
    }

    return it->second;
}

ManejadorUsuarios::~ManejadorUsuarios() {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }

    usuarios.clear();
}