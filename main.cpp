#include <ctime>
#include <iostream>
#include <windows.h>
#include "Funciones.h"
#include "Juego.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	srand(time(NULL));
	Juego snake;
	snake.Jugar();
	
	return 0;
}

