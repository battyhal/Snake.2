#ifndef SNAKE_H
#define SNAKE_H

#include <conio.h>
#include <deque>
#include <iostream>

#include "Constantes.h"
#include "Casilla.h"
#include "Comida.h"
#include "Funciones.h"

class Snake {
private:
	std::deque<Casilla>::iterator it;
	std::deque<Casilla> cuerpo;
protected:
public:
	Snake(char c, char id, int x, int y);
	~Snake();
	
	Casilla Get_Casilla(int i);
	int  Get_Partes_Cuerpo();
	void Borrar_Cola();
	bool Comer(Comida* comida);
	void Mover(int i);
	void Crecer();
	void Dibujar();
};

#endif

