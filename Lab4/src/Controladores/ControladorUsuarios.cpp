#include "../../include/Controladores/ControladorUsuarios.h"
#include "../../include/Manejadores/ManejadorUsuarios.h"

//--
#include "../../include/Manejadores/ManejadorViajes.h"
#include "../../include/Controladores/ControladorFechaActual.h"
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
    return std::vector<DTListarViaje>();
}

std::vector<DTUsuarioViaje> ControladorUsuarios::listarUsuariosViaje(int codigo) {
    return std::vector<DTUsuarioViaje>();
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