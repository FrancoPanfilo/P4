#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string email;
    std::string contrasena;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    getNickname();
    getNombre();
    getEmail();
};

#endif
