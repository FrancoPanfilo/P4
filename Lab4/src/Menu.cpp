#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/Interfaces/IControladorFechaActual.h"
#include "../include/Interfaces/IAltaUsuario.h"
#include "../include/Interfaces/IAltaViaje.h"
#include "../include/Interfaces/IGenerarReserva.h"
#include "../include/Interfaces/ICalificarUsuario.h"
#include "../include/Interfaces/IEliminarViaje.h"
#include "../include/CargaDatos.h"
#include "../include/DTyENUM/DTFecha.h"
#include "../include/DTyENUM/TipoLibreta.h"
#include "../include/DTyENUM/TipoVehiculo.h"
#include "../include/DTyENUM/TipoUsuario.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int Menu::leerEntero()
{
    int valor;
    while (!(std::cin >> valor))
    {
        if (std::cin.eof())
        {
            return 0; // fin de entrada: el llamador (menu) corta el bucle por eof
        }
        std::cin.clear(); // limpia el estado de error dejado por la entrada invalida
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Ingrese un numero: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

float Menu::leerFloat()
{
    float valor;
    while (!(std::cin >> valor))
    {
        if (std::cin.eof())
        {
            return 0.0f;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Ingrese un numero: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

void Menu::leerFecha(int &dia, int &mes, int &anio)
{
    while (!(std::cin >> dia >> mes >> anio))
    {
        if (std::cin.eof())
        {
            dia = mes = anio = 0;
            return;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Fecha invalida. Ingrese dia mes anio: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::altaUsuario()
{
    IAltaUsuario *controlador = Fabrica::getInstance()->getIAltaUsuario();

    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    tipoUsuario = leerEntero();

    if (tipoUsuario != 1 && tipoUsuario != 2)
    {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: ";
    std::getline(std::cin, email);

    bool usuarioOk = false;

    if (tipoUsuario == 1)
    {
        std::string ci;
        std::cout << "Ingrese CI: ";
        std::getline(std::cin, ci);
        usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci);
        if (usuarioOk)
        {
            std::cout << "Pasajero registrado exitosamente.\n";
        }
        else
        {
            std::cout << "No se pudo registrar el pasajero.\n";
        }
    }
    else if (tipoUsuario == 2)
    {
        std::vector<TipoLibreta> libretas;
        int agregarLibreta = 1;
        while (agregarLibreta == 1)
        {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n"
            "0. Moto (Profesional)\n"
            "1. Moto (Amateur)\n"
            "2. Auto (Profesional)\n"
            "3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            tipoLibreta = leerEntero();
            if (tipoLibreta >= 0 && tipoLibreta <= 3)
            {
                libretas.push_back(static_cast<TipoLibreta>(tipoLibreta));
                std::cout << "Libreta agregada.\n";
            }
            else
            {
                std::cout << "Libreta invalida.\n";
            }
            std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
            agregarLibreta = leerEntero();
        }

        usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas);
        if (usuarioOk)
        {
            std::cout << "Conductor registrado exitosamente.\n";
        }
        else
        {
            std::cout << "No se pudo registrar el conductor.\n";
        }

        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1)
        {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: ";
            std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: ";
            capacidad = leerEntero();
            std::cout << "Ingrese marca: ";
            std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: ";
            std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): ";
            tipo = leerEntero();
            int resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, static_cast<TipoVehiculo>(tipo));
            if (resultadoRegistrarVehiculo == -1)
            {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            }
            else if (resultadoRegistrarVehiculo == -2)
            {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            }
            else if (resultadoRegistrarVehiculo == 0)
            {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            agregarVehiculo = leerEntero();
        }
    }
}

void Menu::altaViaje()
{
    IAltaViaje *controlador = Fabrica::getInstance()->getIAltaViaje();

    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: ";
    std::getline(std::cin, nickname);
    std::vector<DTVehiculosConductor> vehiculos = controlador->listarVehiculosConductor(nickname);
    for (DTVehiculosConductor v : vehiculos)
    {
        std::cout << "> Matricula: " << v.getMatricula() << ", Modelo: " << v.getModelo() <<
         ", Capacidad: " << v.getCapacidad() << "\n";
    }

    std::cout << "Ingrese matricula del vehiculo a utilizar: ";
    std::getline(std::cin, matricula);
    bool matriculaValida = false;
    for (DTVehiculosConductor v : vehiculos)
    {
        if (v.getMatricula() == matricula)
        {
            matriculaValida = true;
        }
    }
    if (!matriculaValida)
    {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): ";
    leerFecha(dia, mes, anio);
    std::cout << "Ingrese origen: ";
    std::getline(std::cin, origen);
    std::cout << "Ingrese destino: ";
    std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: ";
    asientos = leerEntero();
    std::cout << "Ingrese precio por asiento: ";
    precio = leerFloat();
    bool viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk)
    {
        std::cout << "Viaje registrado exitosamente.\n";
    }
    else
    {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva()
{
    IGenerarReserva *controlador = Fabrica::getInstance()->getIGenerarReserva();

    std::vector<std::string> pasajeros = controlador->listarPasajeros();
    for (std::string p : pasajeros)
    {
        std::cout << "> " << p << "\n";
    }

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: ";
    std::getline(std::cin, nickname);

    bool nicknameValido = false;
    for (std::string p : pasajeros)
    {
        if (p == nickname)
        {
            nicknameValido = true;
        }
    }
    if (!nicknameValido)
    {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): ";
    leerFecha(dia, mes, anio);
    std::cout << "Ingrese origen: ";
    std::getline(std::cin, origen);
    std::cout << "Ingrese destino: ";
    std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: ";
    asientos = leerEntero();

    std::vector<DTConsultaViaje> viajes = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);
    for (DTConsultaViaje d : viajes)
    {
        std::cout << "> Codigo: " << d.getCodigo() << ", Marca: " << d.getMarca()
                  << ", Modelo: " << d.getModelo() << ", Conductor: " << d.getConductor()
                  << ", CalificacionPromedio: " << d.getCalificacionProm()
                  << ", PrecioTotal: " << d.getPrecioTotal() << "\n";
    }

    bool hayViajes = !viajes.empty();
    if (!hayViajes)
    {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: ";
    codigo = leerEntero();
    bool codigoValido = false;
    for (DTConsultaViaje d : viajes)
    {
        if (d.getCodigo() == codigo)
        {
            codigoValido = true;
        }
    }
    if (!codigoValido)
    {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = controlador->generarReserva(nickname, codigo, asientos);
    if (reservaOk)
    {
        std::cout << "Reserva realizada exitosamente.\n";
    }
    else
    {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario()
{
    ICalificarUsuario *controlador = Fabrica::getInstance()->getICalificarUsuario();

    std::vector<DTUsuario> usuarios = controlador->listarUsuarios();
    for (DTUsuario u : usuarios)
    {
        std::cout << "> Nickname: " << u.getNickname() << ", Nombre: " << u.getNombre() << "\n";
    }
    std::string nickname;
    std::cout << "Ingrese su nickname: ";
    std::getline(std::cin, nickname);
    bool nicknameValido = false;
    for (DTUsuario u : usuarios)
    {
        if (u.getNickname() == nickname)
        {
            nicknameValido = true;
        }
    }
    if (!nicknameValido)
    {
        std::cout << "Nickname invalido.\n";
        return;
    }

    std::vector<DTListarViaje> viajes = controlador->listarViajes(nickname);
    for (DTListarViaje v : viajes)
    {
        std::cout << "> Codigo: " << v.getCodigo() << ", Fecha: " << v.getFecha()
                  << ", Origen: " << v.getOrigen() << ", Destino: " << v.getDestino()
                  << ", Conductor: " << v.getConductor() << "\n";
    }
    int codigo;
    std::cout << "Ingrese codigo del viaje: ";
    codigo = leerEntero();
    bool codigoValido = false;
    for (DTListarViaje v : viajes)
    {
        if (v.getCodigo() == codigo)
        {
            codigoValido = true;
        }
    }
    if (!codigoValido)
    {
        std::cout << "Codigo invalido.\n";
        return;
    }

    std::vector<DTUsuarioViaje> usuariosViaje = controlador->listarUsuariosViaje(codigo);
    for (DTUsuarioViaje uv : usuariosViaje)
    {
        std::string tipoTexto = (uv.getTipo() == TipoUsuario::Conductor) ? "Conductor" : "Pasajero";
        std::cout << "> Nickname: " << uv.getNickname() << ", Tipo: " << tipoTexto << "\n";
    }
    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: ";
    std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): ";
    calificacion = leerEntero();
    bool nicknameCalificadoValido = false;
    for (DTUsuarioViaje uv : usuariosViaje)
    {
        if (uv.getNickname() == nicknameCalificado)
        {
            nicknameCalificadoValido = true;
        }
    }
    if (!nicknameCalificadoValido)
    {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = controlador->calificarUsuario(nicknameCalificado, calificacion);
    if (calificacionOk)
    {
        std::cout << "Calificacion exitosa.\n";
    }
    else
    {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje()
{
    IEliminarViaje *controlador = Fabrica::getInstance()->getIEliminarViaje();

    std::vector<DTListarViaje> viajes = controlador->listarViajes();
    for (DTListarViaje v : viajes)
    {
        std::cout << "> Codigo: " << v.getCodigo() << ", Fecha: " << v.getFecha()
                  << ", Origen: " << v.getOrigen() << ", Destino: " << v.getDestino()
                  << ", Conductor: " << v.getConductor() << "\n";
    }
    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: ";
    codigo = leerEntero();
    bool codigoValido = false;
    for (DTListarViaje v : viajes)
    {
        if (v.getCodigo() == codigo)
        {
            codigoValido = true;
        }
    }
    if (!codigoValido)
    {
        std::cout << "Codigo invalido.\n";
        return;
    }

    DTDetalleViaje detalle = controlador->detalleViaje(codigo);
    std::cout << ">> Viaje <<\n";
    std::cout << "--- Codigo: " << detalle.getCodigo() << ", Fecha: " << detalle.getFecha()
              << ", Origen: " << detalle.getOrigen() << ", Destino: " << detalle.getDestino()
              << ", AsientosPublicados: " << detalle.getAsientosPublicados()
              << ", Precio por asiento: " << detalle.getPrecio() << "\n";
    DTDetalleVehiculo vehiculo = detalle.getVehiculo();
    std::string tipoTexto = (vehiculo.getTipo() == Auto) ? "Auto" : "Moto";
    std::cout << ">> Vehiculo <<\n";
    std::cout << "--- Matricula: " << vehiculo.getMatricula() << ", Capacidad: " << vehiculo.getCapacidad()
              << ", Marca: " << vehiculo.getMarca() << ", Modelo: " << vehiculo.getModelo()
              << ", Tipo: " << tipoTexto << "\n";
    std::cout << ">> Reservas <<\n";
    std::vector<DTDetalleReserva> reservas = detalle.getReservas();
    for (DTDetalleReserva r : reservas)
    {
        std::cout << "--- AsientosReservados: " << r.getAsientosReservados()
                  << ", Fecha: " << r.getFecha() << ", Pasajero: " << r.getPasajero() << "\n";
    }

    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): ";
    confirmar = leerEntero();
    if (confirmar == 1)
    {
        controlador->eliminarViaje();
        std::cout << "Viaje eliminado exitosamente.\n";
    }
    else
    {
        controlador->cancelarEliminarViaje();
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual()
{
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    opFecha = leerEntero();

    Fabrica *fabrica = Fabrica::getInstance();
    IControladorFechaActual *controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1)
    {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    }
    else if (opFecha == 2)
    {
        int dia, mes, anio;
        std::cout << "Ingrese dia: ";
        dia = leerEntero();
        std::cout << "Ingrese mes: ";
        mes = leerEntero();
        std::cout << "Ingrese anio: ";
        anio = leerEntero();
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    }
    else
    {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos()
{
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu()
{
    int opcion = -1;
    while (opcion != 8)
    {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        opcion = leerEntero();
        if (std::cin.eof())
        {
            break;
        }

        switch (opcion)
        {
        case 1:
            altaUsuario();
            break;
        case 2:
            altaViaje();
            break;
        case 3:
            generarReserva();
            break;
        case 4:
            calificarUsuario();
            break;
        case 5:
            eliminarViaje();
            break;
        case 6:
            administrarFechaActual();
            break;
        case 7:
            cargarDatos();
            break;
        case 8:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opcion invalida.\n";
        }
    }
}
