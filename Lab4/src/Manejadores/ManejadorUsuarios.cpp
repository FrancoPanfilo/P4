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

    // (altaPasajero DCM)
    
    // 1.1: e := exists(nickname)
    bool e = usuarios.find(nickname) != usuarios.end(); //.end() apunta justo despues del ultimo elemento

    // Si e == TRUE retorna FALSE
    if (e) { return false; }

    // 1.2a [not e]: p := create(...)
    Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);

    // 1.3a: add(p)
    usuarios[nickname] = p;

    // retorna TRUE
    return true;
}

bool ManejadorUsuarios::nuevoConductor(std::string nickname,
                                        std::string nombre,
                                        std::string contrasena,
                                        std::string email,
                                        std::vector<TipoLibreta> libretas) {
    // (altaConductor DCM)
    
    // 1.1: e := exists(nickname)
    bool e = usuarios.find(nickname) != usuarios.end();

    // Si e == TRUE retorna FALSE
    if (e) { return false; }

    // 1.2a [not e]: p := create(...)
    Conductor* c = new Conductor(nickname, nombre, contrasena, email, libretas);

    // 1.3a: add(p)
    usuarios[nickname] = c;

    // retorna TRUE
    return true;

}

int ManejadorUsuarios::registrarVehiculo(std::string nickname,
                                          std::string matricula,
                                          int capacidad,
                                          std::string marca,
                                          std::string modelo,
                                          TipoVehiculo tipo) {

    // (registrarVehiculo DCM)

    // 2.1: c := find(nickname)
    Usuario* u = getUsuario(nickname);

    if (u == nullptr) {
        return -2; // No existe el usuario
    }

    Conductor* c = dynamic_cast<Conductor*>(u);
    //Performs checks at runtime. If the object being pointed to is not of the target type (or a valid derived type), the cast returns nullptr.    

    if (c == nullptr) {
        return -2; // Existe usuario, pero no es conductor
    }

    // 2.2: tl := tieneLibreta(tipo)
    bool tieneLibreta = c->tieneLibreta(tipo);

    if (!tieneLibreta) { return -2; }
    // No tiene tipo de licencia para el vehículo

    // 2.4: nuevoVehiculo(...)
    ManejadorVehiculos* mv = ManejadorVehiculos::getInstance();

    Vehiculo* v = mv->nuevoVehiculo(matricula, capacidad, marca, modelo, tipo);

    if (v == nullptr) { return -1; }
    // Matrícula repetida u otro error al crear

    // 2.4.3.1: add(v)
    c->agregarVehiculo(v);

    return 0;
}

std::vector<std::string> ManejadorUsuarios::listarPasajeros() {

  // (listarPasajeros DCM)

  std::vector<std::string> resultado;

  // 1* [foreach]: u := next()
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* u = it->second;

        Pasajero* p = dynamic_cast<Pasajero*>(u);

        // 2* nick := getNickname() : String
        if (p != nullptr) {
            resultado.push_back(p->getNickname());
        }
    }

    return resultado;
}

std::vector<DTUsuario> ManejadorUsuarios::listarUsuarios() {

    // (listarUsuarios DCM)

    std::vector<DTUsuario> resultado;

    // 1* [foreach]: u := next()
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* u = it->second;

        // 2* DTUsuario := getDTUsuario()
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

ManejadorUsuarios::~ManejadorUsuarios() {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}
