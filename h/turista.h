#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "Experiencia.h"

class Turista
{
private:
    std::string ci;
    std::string nombre;
    std::string email;
    std::set<Experiencia *> experiencias; // asociación con Experiencia, turista participa en muchas experiencias.

public:
    Turista(std::string ci, std::string nombre, std::string email);
    ~Turista();
    std::string toString();
    std::set<std::string> listarExperiencias(DTFecha desde, float min, float max);
    void agregarExperiencia(Experiencia *e);
    std::string getNombre();
    std::string getEmail();
    std::string getCi();
};

#endif
