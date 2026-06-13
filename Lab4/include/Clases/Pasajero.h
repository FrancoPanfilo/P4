#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>
#include <vector>
#include <algorithm>

class Reserva;

class Pasajero : public Usuario {
private:
    std::string ci;
    std::vector<Reserva *> reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    std::string getCI();
    void agregarReserva(Reserva *reserva);
    std::vector<Reserva*> getReservas();
    void quitarReserva(Reserva* reserva);
};

#endif
