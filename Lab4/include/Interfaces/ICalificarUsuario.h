#ifndef ICALIFICAR_USUARIO_H
#define ICALIFICAR_USUARIO_H

#include <vector>
#include <string>

#include "../DTyENUM/DTUsuario.h"
#include "../DTyENUM/DTListarViaje.h"
#include "../DTyENUM/DTUsuarioViaje.h"

class ICalificarUsuario {
public:    
    virtual std::vector<DTUsuario> listarUsuarios() = 0;
    virtual std::vector<DTListarViaje> listarViajes(std::string nickname) = 0;
    virtual std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo) = 0;
    virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;
    virtual ~ICalificarUsuario() {}
};

#endif