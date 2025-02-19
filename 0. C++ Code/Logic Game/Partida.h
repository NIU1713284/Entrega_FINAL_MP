#ifndef PARTIDA
#define PARTIDA

#include <ctime>
#include <iostream>

#include "./Joc.h"
#include "./InfoJoc.h"
#include "LlistaFigura.h"
#include "LlistaEspera.h"


const int PUNTS_FIGURA = 10;
const int PUNTS_FILA = 100;
const int DOBLE_FILA = 75;
const int TRIPLE_FILA = 100;
const int QUADRUPLE_FILA = 120;

const int CANVI_NIVELL = 200;
const double VELOCITAT_INICIAL = 1.0;
const double CANVI_VELOCITAT = 0.75;

typedef enum
{
	MODE_NORMAL,
	MODE_TEST
} ModeJoc;

class Partida
{
public:
	Partida() : m_mode(MODE_NORMAL), m_temps(0.0), m_punts(0), m_nivell(1), m_velocitat(VELOCITAT_INICIAL), m_final(false)
	{
		srand(time(0));
	}
	Partida(ModeJoc mode) : m_mode(mode), m_temps(0.0), m_punts(0), m_nivell(1), m_velocitat(VELOCITAT_INICIAL), m_final(false)
	{
		srand(time(0));
	}
	void inicialitza(const string& fitxer1, const string& fitxer2, const string& fitxer3);		
	void actualitza(float deltaTime);
	int getPuntuacio() const { return m_punts; }
private:
	Joc m_joc;
	ModeJoc m_mode;

	
	int m_punts;
	int m_nivell;
	double m_temps;
	double m_velocitat;
	bool m_final;

	LlistaFigura m_figura;
	LlistaEspera m_desplas;

	void acturalitzar(int filesEliminades);

	void iniciFigura(const string& nomFitxer);
	void iniciDesplas(const string& nomFitxer);

	void canviNormal(float deltaTime);
	void canviTest(float deltaTime);

};
#endif
