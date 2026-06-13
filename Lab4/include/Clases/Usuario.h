#ifndef USUARIO_H
#define USUARIO_H

#include <string>

//---
#include "Calificacion.h"
#include <vector>
//---

class DTUsuario;
class Reserva;

class Usuario
{
protected:
    std::string nickname;
    std::string nombre;
    std::string email;
    std::string contrasena;

    //---
    std::vector<Calificacion *> calificacionesRecibidas;
    //---

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    //--
    void agregarCalificacion(Calificacion* calificacion);
    std::vector<Calificacion *> getCalificacionesRecibidas();
    // elimina (y libera) las calificaciones que cuelgan de la reserva dada
    void quitarCalificacionesDeReserva(Reserva* reserva);
    //--

    std::string getNickname();
    std::string getNombre();
    std::string getEmail();
    DTUsuario getDTUsuario();
};

#endif
