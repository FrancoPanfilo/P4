#include <iostream>

#include <vector>
#include "h/experiencia.h"
#include "h/turista.h"
#include "h/alojamiento.h"
#include "h/DTExpe.h"
#include "h/DTFecha.h"
#include "h/eventoCultural.h"
#include "h/tourGuiado.h"
using namespace std;

vector<Experiencia *> experiencias;
vector<Alojamiento *> alojamientos;
vector<Turista *> turistas;
vector<TourGuiado *> tourGuiados;
vector<EventoCultural *> eventosCulturales;

void parte_a()
{
	DTFecha fecha1(18, 5, 2020);
	Alojamiento *a1 = new Alojamiento("ALX5489", "Hotel moderno", 30, fecha1, "Hotel Lindorf", AllInclusive, 5);
	DTFecha fecha2 = DTFecha(10, 2, 2025);
	Alojamiento *a2 = new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, fecha2, "Hotel SeaView", MediaPension, 15);
	alojamientos.push_back(a1);
	alojamientos.push_back(a2);
}

void parte_b()
{
	DTFecha fechat1(29, 8, 2024);
	vector<string> lugarest1;
	lugarest1.push_back("Plaza Independencia");
	lugarest1.push_back("Plaza Matriz");
	TourGuiado *t1 = new TourGuiado("TGO4657", "Plazas de Montevideo", 10, fechat1, "Paseos SA", lugarest1);

	DTFecha fechat2(29, 8, 2024);

	vector<string> lugarest2;
	lugarest2.push_back("Puerta de la Ciudadela");
	lugarest2.push_back("Mausoleo");
	lugarest2.push_back("Cabildo");
	lugarest2.push_back("Palacio Salvo");

	TourGuiado *t2 = new TourGuiado("TGR3257", "Puntos emblematicos", 5, fechat2, "Recorre", lugarest2);
	tourGuiados.push_back(t1);
	tourGuiados.push_back(t2);
}

void parte_c()
{
	DTFecha fecha(29, 10, 2025);
	EventoCultural *e1 = new EventoCultural("ECP1346", "Danza en el Solis", 10, fecha, "Teatro Solis", true);
	eventosCulturales.push_back(e1);
}

void parte_d()

{
	for (int i = 0; i < (int)tourGuiados.size(); i++)
	{
		cout << "TourGuiado " << i + 1 << ": " << endl;
		cout << tourGuiados[i]->getDT() << endl;
	}
	for (int i = 0; i < (int)eventosCulturales.size(); i++)
	{
		cout << "EventoCultural " << i + 1 << ": " << endl;
		cout << eventosCulturales[i]->getDT() << endl;
	}
	for (int i = 0; i < (int)alojamientos.size(); i++)
	{
		cout << "Alojamiento " << i + 1 << ": " << endl;
		cout << alojamientos[i]->getDT() << endl;
	}
}

void parte_e()
{
	Turista *turista1 = new Turista("4.951.278-9", "Vanesa Castro", "vcastro.uy@servidor.net");
	Turista *turista2 = new Turista("1.535.442-0", "Karen Santos", "karen.s89@internet.uy");
	turistas.push_back(turista1);
	turistas.push_back(turista2);
}

void parte_f()
{
	for (int i = 0; i < (int)turistas.size(); i++)
	{
		cout << "Turista: " << i + 1 << ": " << endl;
		cout << turistas[i]->toString() << endl;
	}
}

Turista *buscarPorCI(string ci)
{
	for (int i = 0; i < (int)turistas.size(); i++)
		if (turistas[i]->getCi() == ci)
			return turistas[i];
	return NULL;
}

Experiencia *buscarPorCodigo(string codigo)
{
	for (int i = 0; i < (int)alojamientos.size(); i++)
		if (alojamientos[i]->getCodigoReserva() == codigo)
			return alojamientos[i];
	for (int i = 0; i < (int)tourGuiados.size(); i++)
		if (tourGuiados[i]->getCodigoReserva() == codigo)
			return tourGuiados[i];
	for (int i = 0; i < (int)eventosCulturales.size(); i++)
		if (eventosCulturales[i]->getCodigoReserva() == codigo)
			return eventosCulturales[i];
	return NULL;
}

void parte_g()
{
	Turista *t1 = buscarPorCI("4.951.278-9");
	Turista *t2 = buscarPorCI("1.535.442-0");
	Experiencia *e1 = buscarPorCodigo("ALX5489");
	Experiencia *e2 = buscarPorCodigo("ALJ4789");
	Experiencia *e3 = buscarPorCodigo("TGR3257");
	Experiencia *e4 = buscarPorCodigo("ECP1346");
	Experiencia *e5 = buscarPorCodigo("TGO4657");
	t1->agregarExperiencia(e1);
	e1->agregarTurista(t1);
	t1->agregarExperiencia(e2);
	e2->agregarTurista(t1);
	t1->agregarExperiencia(e3);
	e3->agregarTurista(t1);
	t1->agregarExperiencia(e4);
	e4->agregarTurista(t1);
	t2->agregarExperiencia(e5);
	e5->agregarTurista(t2);
	t2->agregarExperiencia(e3);
	e3->agregarTurista(t2);
	/* 	int experienciasVinculadas = 0;
		for (int i = 0; i < (int)experiencias.size(); i++)
		{
			experienciasVinculadas += experiencias[i]->getTuristas().size();
		}
		int turistasVinculados = 0;
		for (int i = 0; i < (int)turistas.size(); i++)
		{
			DTFecha f = DTFecha(1, 1, 2020);
			turistasVinculados + turistas[i]->listarExperiencias(f, 0, 10000).size();

		}
		cout << "Experiencias vinculadas: " << experienciasVinculadas << endl;
		cout << "Turistas vinculados: " << turistasVinculados << endl; */
}

void parte_h()
{
	DTFecha fecha(10, 12, 2023);
	for (int i = 0; i < (int)turistas.size(); i++)
	{
		if (turistas[i] != NULL && turistas[i]->getCi() == "4.951.278-9")
		{
			vector<string> res = turistas[i]->listarExperiencias(fecha, 0, 1000);
			for (int j = 0; j < (int)res.size(); j++)
			{
				cout << res[j] << endl;
			}
		}
	}
}

void parte_i()
{
	for (int i = 0; i < (int)tourGuiados.size(); i++)
	{
		if (tourGuiados[i] != NULL && tourGuiados[i]->getCodigoReserva() == "TGR3257")
		{
			tourGuiados[i]->eliminarExperiencia(); // elimina relaciones y hace delete this internamente
			tourGuiados.erase(tourGuiados.begin() + i);
			break;
		}
	}
}

void parte_j()
{
	DTFecha fecha(10, 12, 2023);
	Turista *t1 = buscarPorCI("1.535.442-0");
	if (t1 != NULL)
	{
		vector<string> res = t1->listarExperiencias(fecha, 0, 1000);
		for (int j = 0; j < (int)res.size(); j++)
		{
			cout << "Experiencia " << j + 1 << ": " << "  " << res[j] << endl;
		}
	}
}

void parte_k()
{
	for (int i = 0; i < (int)tourGuiados.size(); i++)
	{
		cout << "TourGuiado " << i + 1 << ": " << endl;
		cout << tourGuiados[i]->getDT() << endl;
	}
	for (int i = 0; i < (int)eventosCulturales.size(); i++)
	{
		cout << "EventoCultural " << i + 1 << ": " << endl;
		cout << eventosCulturales[i]->getDT() << endl;
	}
	for (int i = 0; i < (int)alojamientos.size(); i++)
	{
		cout << "Alojamiento " << i + 1 << ": " << endl;
		cout << alojamientos[i]->getDT() << endl;
	}
}

void cleanUp()
{
	for (int i = 0; i < (int)experiencias.size(); i++)
		delete experiencias[i];
	experiencias.clear();

	for (int i = 0; i < (int)turistas.size(); i++)
		delete turistas[i];
	turistas.clear();
	for (int i = 0; i < (int)alojamientos.size(); i++)
		delete alojamientos[i];
	alojamientos.clear();
	for (int i = 0; i < (int)tourGuiados.size(); i++)
		delete tourGuiados[i];
	tourGuiados.clear();
	for (int i = 0; i < (int)eventosCulturales.size(); i++)
		delete eventosCulturales[i];
	eventosCulturales.clear();
}

int main()
{
	cout << "parte_a" << endl;
	parte_a();
	cout << "parte_b" << endl;
	parte_b();
	cout << "parte_c" << endl;
	parte_c();
	cout << "parte_d" << endl;
	parte_d();
	cout << "parte_e" << endl;
	parte_e();
	cout << "parte_f" << endl;
	parte_f();
	cout << "parte_g" << endl;
	parte_g();
	cout << "parte_h" << endl;
	parte_h();
	cout << "parte_i" << endl;
	parte_i();
	cout << "parte_j" << endl;
	parte_j();
	cout << "parte_k" << endl;
	parte_k();
	cout << "cleanUp" << endl;
	cleanUp();
	cout << "fin" << endl;

	return 0;
}