#ifndef MANEJADOR_USUARIOS_H
#define MANEJADOR_USUARIOS_H

#include <map>
#include <string>
#include <set>

#include "../Clases/Usuario.h"
#include "../Clases/Pasajero.h"
#include "../Clases/Conductor.h"
#include "../DTyENUM/DTUsuario.h"
#include "../DTyENUM/TipoLibreta.h"

class ManejadorUsuarios {
private:
    static ManejadorUsuarios* instancia;

    std::map<std::string, Usuario*> usuarios;

    ManejadorUsuarios();

public:
    static ManejadorUsuarios* getInstance();

    //bool existeUsuario(std::string nickname); //posible    

    bool nuevoPasajero(std::string nickname,
                            std::string nombre,
                            std::string contrasena,
                            std::string email,
                            std::string ci);

    bool nuevoConductor(std::string nickname,
                            std::string nombre,
                            std::string contrasena,
                            std::string email,
                            std::set<TipoLibreta> libretas);

    int registrarVehiculo(std::string nickname,
                            std::string matricula,
                            int capacidad,
                            std::string marca,
                            std::string modelo,
                            TipoVehiculo tipo);                          

    std::set<DTUsuario> listarPasajeros();

    Pasajero* findPasajero(std::string nickname);
        
    Usuario* getUsuario(std::string nickname);     

    ~ManejadorUsuarios();
};

#endif