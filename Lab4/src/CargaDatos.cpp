#include "../include/CargaDatos.h"
#include <iostream>
#include "../include/DTyENUM/TipoLibreta.h"
#include "../include/Interfaces/IAltaUsuario.h"
#include "../include/Interfaces/ICalificarUsuario.h"
#include "../include/Controladores/ControladorUsuarios.h"
#include "../include/Controladores/ControladorViajes.h"
#include "../include/Controladores/ControladorFechaActual.h"

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    ControladorUsuarios* contusuario = ControladorUsuarios::getInstance();
    ControladorViajes* contviajes = ControladorViajes::getInstance();
    ControladorFechaActual* contfechaactual = ControladorFechaActual::getInstance();

    //conductores

    std::vector<TipoLibreta> l;

    l.push_back(TipoLibreta::AutoAmateur);
    contusuario->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", l);
    l.clear();   
    
    l.push_back(TipoLibreta::AutoProfesional);
    contusuario->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", l);
    l.clear();   
    
    l.push_back(TipoLibreta::MotoAmateur);
    contusuario->altaConductor("greg_m", "Diego Rodriguez", "drodriguez8", "diegorodriguez@fing.edu.uy", l);
    l.clear();   
    
    l.push_back(TipoLibreta::MotoProfesional);
    contusuario->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", l);
    l.clear();   
    
    l.push_back(TipoLibreta::AutoProfesional);
    l.push_back(TipoLibreta::MotoAmateur);
    contusuario->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", l);
    l.clear();   

    //pasajeros
    contusuario->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "14923042");
    contusuario->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "41038591");
    contusuario->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "38471125");
    contusuario->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "29564030");
    contusuario->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "50217843");

    //vehiculos

    contusuario->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
    contusuario->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", TipoVehiculo::Auto);
    contusuario->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", TipoVehiculo::Auto); 
    contusuario->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", TipoVehiculo::Auto);
    contusuario->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", TipoVehiculo::Moto);
    contusuario->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", TipoVehiculo::Moto);
    contusuario->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", TipoVehiculo::Auto);
    contusuario->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", TipoVehiculo::Moto);

    //viajes

    contviajes->altaViaje("ABJ4586", DTFecha(21,10,2026), "montevideo", "mercedes", 4, 200);
    contviajes->altaViaje("ACM4455", DTFecha(20,10,2026), "young", "montevideo", 5, 250);
    contviajes->altaViaje("BAS7895", DTFecha(20,10,2026), "young", "montevideo", 4, 200);
    contviajes->altaViaje("BCS4105", DTFecha(21,10,2026), "montevideo", "mercedes", 9, 200);
    contviajes->altaViaje("LDA4875", DTFecha(21,10,2026), "montevideo", "mercedes", 1, 300);
    contviajes->altaViaje("PDB1205", DTFecha(21,10,2026), "montevideo", "mercedes", 1, 350);
    contviajes->altaViaje("SBJ4874", DTFecha(21,10,2026), "montevideo", "mercedes", 4, 260);
    contviajes->altaViaje("SCF2469", DTFecha(20,10,2026), "montevideo", "cerro chato", 1, 150);
    contviajes->altaViaje("ABJ4586", DTFecha(15,3,2026), "montevideo", "colonia", 4, 140);
    contviajes->altaViaje("BCS4105", DTFecha(15,3,2026), "montevideo", "colonia", 9, 180);
    contviajes->altaViaje("SBJ4874", DTFecha(15,3,2026), "montevideo", "colonia", 1, 100);
    contviajes->altaViaje("SBJ4874", DTFecha(14,3,2026), "montevideo", "colonia", 4, 600);
    contviajes->altaViaje("LDA4875", DTFecha(20,10,2026), "young", "montevideo", 1, 250);

    //reservas


    contfechaactual->setFecha(DTFecha(14,3,2026));
    contviajes->generarReserva("santi_90", 9, 2);

    contfechaactual->setFecha(DTFecha(14,3,2026));
    contviajes->generarReserva("mari_b", 9, 1);

    contfechaactual->setFecha(DTFecha(14,3,2026));
    contviajes->generarReserva("nacho_f", 10, 5);

    contfechaactual->setFecha(DTFecha(14,3,2026));
    contviajes->generarReserva("valen_uy", 10, 3);

    contfechaactual->setFecha(DTFecha(14,3,2026));
    contviajes->generarReserva("joaco_r", 10, 1);

    contfechaactual->setFecha(DTFecha(13,3,2026));    
    contviajes->generarReserva("mari_b", 12, 1);

    contfechaactual->setFecha(DTFecha(13,3,2026));
    contviajes->generarReserva("nacho_f", 12, 1);

    contfechaactual->setFecha(DTFecha(1,6,2026));
    contviajes->generarReserva("mari_b", 1, 2);

    contfechaactual->setFecha(DTFecha(13,3,2026));
    contviajes->generarReserva("nacho_f", 9, 1);


    //calificaciones

// santi_90	9	matil92	4
// mari_b	9	matil92	4
// matil92	9	mari_b	3
// ana_silva	10	valen_uy	5
// ana_silva	10	joaco_r	5
// mari_b	12	carlos_r	5
// carlos_r	12	nacho_f	5



    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
