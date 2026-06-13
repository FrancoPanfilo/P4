#include "../../include/Controladores/ControladorUsuarios.h"
#include "../../include/Manejadores/ManejadorUsuarios.h"

//--
#include "../../include/Manejadores/ManejadorViajes.h"
#include "../../include/Controladores/ControladorFechaActual.h"
#include "../../include/Clases/Vehiculo.h"
//--

ControladorUsuarios* ControladorUsuarios::instancia = nullptr;

ControladorUsuarios::ControladorUsuarios() {
    nicknameMemoria = "";
    codigoMemoria = 0;
}

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuarios();
    }
    return instancia;
}

bool ControladorUsuarios::altaPasajero(std::string nickname, std::string nombre,
                                       std::string contrasena, std::string email,
                                       std::string ci) {
    return ManejadorUsuarios::getInstance()->nuevoPasajero(nickname, nombre,
                                                           contrasena, email, ci);
}

bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre,
                                        std::string contrasena, std::string email,
                                        std::vector<TipoLibreta> libretas) {
    return ManejadorUsuarios::getInstance()->nuevoConductor(nickname, nombre,
                                                            contrasena, email, libretas);
}

int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula,
                                           int capacidad, std::string marca,
                                           std::string modelo, TipoVehiculo tipo) {
    return ManejadorUsuarios::getInstance()->registrarVehiculo(nickname, matricula,
                                                               capacidad, marca, modelo, tipo);
}

std::vector<DTUsuario> ControladorUsuarios::listarUsuarios() {
    return ManejadorUsuarios::getInstance()->listarUsuarios();
}

std::vector<DTListarViaje> ControladorUsuarios::listarViajes(std::string nickname) {

    std::vector<DTListarViaje> res;    

    this->nicknameMemoria = nickname; // postcondición: se guarda el nickname recibido

    Usuario* u = ManejadorUsuarios::getInstance()->getUsuario(nickname);

    Pasajero* p = dynamic_cast<Pasajero*>(u);
    if (p != nullptr) {
        std::vector<Reserva*> reservas = p->getReservas();

        for (Reserva* r : reservas) {
            Viaje* v = r->getViaje();

            DTListarViaje dt = v->getDTListarViaje();
            res.push_back(dt);
        }

        return res;
    }

    Conductor* c = dynamic_cast<Conductor*>(u);
    if (c != nullptr) {
        std::list<Vehiculo*> vehiculos = c->getVehiculos();

        for (Vehiculo* vehiculo : vehiculos) {
            std::list<Viaje*> viajes = vehiculo->getViajes();

            for (Viaje* v : viajes) {
                DTListarViaje dt = v->getDTListarViaje();
                res.push_back(dt);
            }
        }
    }

    return res;

}

std::vector<DTUsuarioViaje> ControladorUsuarios::listarUsuariosViaje(int codigo) {
    
    std::vector<DTUsuarioViaje> res;

    this->codigoMemoria = codigo; // postcondición: se guarda el código recibido

    Viaje* viaje = ManejadorViajes::getInstance()->obtenerViaje(codigo);
    if (viaje == nullptr) {
        return res;
    }

    std::vector<Reserva*> reservas = viaje->getReservas();

    for (Reserva* reserva : reservas) {
        Pasajero* pasajero = reserva->getPasajero();

        DTUsuarioViaje dt(pasajero->getNickname(),TipoUsuario::Pasajero);

        res.push_back(dt);
    }

    Vehiculo* vehiculo = viaje->getVehiculo();

    DTUsuarioViaje dtConductor(vehiculo->getNicknameConductor(),TipoUsuario::Conductor);

    res.push_back(dtConductor);

    return res;

}

bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion)
{
    
    if (calificacion < 1 || calificacion > 5) { return false; } //valida el puntaje

    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    ManejadorViajes* mv = ManejadorViajes::getInstance();
    
    Usuario* usuarioCalificador = mu->getUsuario(nicknameMemoria);  //busca usuario calificador
    Usuario* usuarioCalificado = mu->getUsuario(nicknameCalificado); //busca usuario calificado

    if (usuarioCalificador == nullptr || usuarioCalificado == nullptr) { return false; } //usuario no encotrado retorna false

    if (usuarioCalificador->getNickname() == usuarioCalificado->getNickname()) { return false; } //evita autocalificación

    //busca la reserva del usuario calificado en el viaje recordado
    Reserva* reserva = mv->getReservaUsuarioCalificado(codigoMemoria, nicknameCalificado);

    if (reserva == nullptr) { return false; } //si no hay reserva retorna false

    //obtengo fecha actual con controlador
    DTFecha fechaActual = ControladorFechaActual::getInstance()->getFecha();

    //crea la calificación
    Calificacion* nuevaCalificacion = new Calificacion(fechaActual, calificacion, usuarioCalificador, reserva);

    //la agrega al usuario calificado
    usuarioCalificador->agregarCalificacion(nuevaCalificacion);

    nicknameMemoria = "";
    codigoMemoria = 0;

    return true;
}