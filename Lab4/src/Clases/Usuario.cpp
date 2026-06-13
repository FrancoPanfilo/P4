#include "../../include/Clases/Usuario.h"
#include "../../include/DTyENUM/DTUsuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() {
    return nickname;
}

std::string Usuario::getNombre() {
    return nombre;
}

std::string Usuario::getEmail() {
    return email;
}

DTUsuario Usuario::getDTUsuario() {
    return DTUsuario(nickname, nombre);
}

//--
void Usuario::agregarCalificacion(Calificacion* calificacion){
    calificacionesRecibidas.push_back(calificacion);
}

std::vector<Calificacion *> Usuario::getCalificacionesRecibidas(){
    return calificacionesRecibidas;
}

void Usuario::quitarCalificacionesDeReserva(Reserva* reserva){
    for (auto it = calificacionesRecibidas.begin(); it != calificacionesRecibidas.end(); ){
        if ((*it)->getReserva() == reserva){
            delete *it;                                  // libera la Calificacion
            it = calificacionesRecibidas.erase(it);      // la quita de la coleccion
        } else {
            ++it;
        }
    }
}
//--