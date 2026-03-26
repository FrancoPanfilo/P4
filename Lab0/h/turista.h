#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "experiencia.h"
using namespace std;

class Experiencia; // declaración adelantada

class Turista
{
private:
    string ci;
    string nombre;
    string email;
    vector<Experiencia *> experiencias;

public:
    Turista(const string &ci, const string &nombre, const string &email);
    ~Turista();
    string toString() const;
    vector<string> listarExperiencias(DTFecha &desde, float min, float max) const;
    void agregarExperiencia(Experiencia *e);
    void quitarExperiencia(string codigo);
    string getNombre() const;
    string getEmail() const;
    string getCi() const;
};

#endif
