#include "../../include/Clases/Pasajero.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {}

std::string Pasajero::getCI(){
    return this->ci;
}

void Pasajero::agregarReserva(Reserva *reserva) {
    this->reservas.push_back(reserva);
}
