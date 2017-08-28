#include "Mapa.h"

Mapa::Mapa() 
{
	/*for(int i = 0; i < ALTO; i++)
	{
		for(int j = 0; j < ANCHO; j++)
		{
			mapa[j][i].Set_Dibujo(' ');
		}
	}*/
}

void Mapa::Set_Dibujo_Casilla(int i, int j, char c)
{			
	mapa[j][i].Set_Dibujo(c);			
}

Mapa::~Mapa() {}

void Mapa::Dibujar_Marco()
{	
	char esquinaInfDcha = 188;
	char esquinaInfIzda = 200;
	char esquinaSupDcha = 187;
	char esquinaSupIzda = 201;
	char lateral = 186;
	char suelo = 205;
	for(int j = 0; j <= ALTO; j++)
	{
		Funciones::Goto_XY(0, j);
		std::cout << lateral;
		Funciones::Goto_XY(ANCHO + 1, j);
		std::cout << lateral;
		
		for(int k = 0; k <= ANCHO; k++)
		{
			Funciones::Goto_XY(k, 0);
			std::cout << suelo;
			Funciones::Goto_XY(k, ALTO + 1);
			std::cout << suelo;
		}
	}
	Funciones::Goto_XY(0, 0);
	std::cout << esquinaSupIzda;
	Funciones::Goto_XY(0, ALTO + 1);
	std::cout << esquinaInfIzda;
	Funciones::Goto_XY(ANCHO + 1, 0);
	std::cout << esquinaSupDcha;
	Funciones::Goto_XY(ANCHO + 1, ALTO + 1);
	std::cout << esquinaInfDcha;	
}
