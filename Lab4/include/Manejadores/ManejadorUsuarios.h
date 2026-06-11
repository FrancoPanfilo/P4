#ifndef MANEJADOR_USUARIOS_H
#define MANEJADOR_USUARIOS_H

#include <map>
#include <string>
#include <vector>

#include "../Clases/Usuario.h"
#include "../Clases/Pasajero.h"
#include "../Clases/Conductor.h"
#include "../DTyENUM/DTUsuario.h"
#include "../DTyENUM/TipoLibreta.h"
#include "../DTyENUM/TipoVehiculo.h"

class ManejadorUsuarios {
private:
    static ManejadorUsuarios* instancia;

    std::map<std::string, Usuario*> usuarios; //colección de usuarios

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
                            std::vector<TipoLibreta> libretas);

    int registrarVehiculo(std::string nickname,
                            std::string matricula,
                            int capacidad,
                            std::string marca,
                            std::string modelo,
                            TipoVehiculo tipo);                          

    std::vector<std::string> listarPasajeros();

    std::vector<DTUsuario> listarUsuarios();

    Pasajero* findPasajero(std::string nickname);
        
    Usuario* getUsuario(std::string nickname);     

    ~ManejadorUsuarios();
};

#endif