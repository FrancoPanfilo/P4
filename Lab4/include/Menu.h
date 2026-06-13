#ifndef MENU_H
#define MENU_H

class Menu
{
private:
    void altaUsuario();
    void altaViaje();
    void generarReserva();
    void calificarUsuario();
    void eliminarViaje();
    void administrarFechaActual();
    void cargarDatos();

    // para que no se buguee al poner una letra en lugar de un numero
    int leerEntero();
    float leerFloat();
    void leerFecha(int &dia, int &mes, int &anio);

public:
    void mostrarMenu();
};

#endif
