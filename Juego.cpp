#include "Juego.h"

Juego::Juego() 
{
	system("cls");
	Info_Teclas();
	tablero.Dibujar_Marco();
	int max = ANCHO;
	int min = 0;
	int aleatorioX = 0;
	int aleatorioY = 0;
	do
	{
		aleatorioX = rand() % (max - min) + min;
		aleatorioY = rand() % (max - min) + min;
	}while(aleatorioX > ANCHO - 1 || aleatorioY > ALTO - 1
		   || aleatorioX < 2 || aleatorioY < 2);
	comida = new Comida('*', aleatorioX, aleatorioY);
	
	max = 5;
	min = 1;
	int aleatorio = 0;
	do
	{
		aleatorio = rand() % (max - min) + min;
	}while(aleatorio > 4 || aleatorio < 1);
	switch(aleatorio)
	{
	case 1:
	{
		arriba    = false;
		derecha   = true;
		izquierda = true;
		ultimo_movimiento = ABAJO;
	}
	break;
	case 2:
	{
		abajo     = false;
		derecha   = true;
		izquierda = true;
		ultimo_movimiento = ARRIBA;
	}
	break;
	case 3:
	{
		abajo     = true;
		arriba    = true;
		izquierda = false;
		ultimo_movimiento = DERECHA;
	}
	break;
	case 4:
	{
		abajo     = true;
		arriba    = true;
		derecha   = false;
		ultimo_movimiento = IZQUIERDA;
	}
	break;
	} // Fin switch
	snake = new Snake('<', 'H', ALTO / 4, ANCHO / 4);
	game_over = false;
}

Juego::~Juego() 
{
	comida = 0;
	snake  = 0;
	delete comida;
	delete snake;
}

void Juego::Actualizar()
{	
	while(!game_over)
	{
		snake->Mover(ultimo_movimiento);
		if(kbhit())
		{
			char tecla = getch();
			if(tecla == ESCAPE)
			{
				game_over = true;
			}
			if(tecla == ABAJO && snake->Get_Casilla(0).Get_Y() < ALTO)
			{
				if(abajo)
				{
					arriba    = false;
					derecha   = true;
					izquierda = true;
					snake->Mover(ABAJO);
					ultimo_movimiento = ABAJO;
				}
			}
			if(tecla == ARRIBA && snake->Get_Casilla(0).Get_Y() > 0)
			{
				if(arriba)
				{
					abajo     = false;
					derecha   = true;
					izquierda = true;
					snake->Mover(ARRIBA);
					ultimo_movimiento = ARRIBA;
				}
			}
			if(tecla == DERECHA && snake->Get_Casilla(0).Get_X() < ANCHO)
			{
				if(derecha)
				{
					abajo     = true;
					arriba    = true;
					izquierda = false;
					snake->Mover(DERECHA);
					ultimo_movimiento = DERECHA;
				}
			}
			if(tecla == IZQUIERDA && snake->Get_Casilla(0).Get_X() > 0)
			{
				if(izquierda)
				{
					abajo   = true;
					arriba  = true;
					derecha = false;
					snake->Mover(IZQUIERDA);
					ultimo_movimiento = IZQUIERDA;
				}
			}
		} // Fin if(kbhit())
		if(snake->Comer(comida))
		{
			snake->Crecer();
			int max = ANCHO;
			int min = 0;
			int aleatorioX = 0;
			int aleatorioY = 0;
			do
			{
				aleatorioX = rand() % (max - min) + min;
				aleatorioY = rand() % (max - min) + min;
			} while(aleatorioX > ANCHO - 1 || aleatorioY > ALTO - 1
					|| aleatorioX < 2 || aleatorioY < 2);
			comida = 0;
			comida = new Comida('*', aleatorioX, aleatorioY);
		}
		comida->Dibujar();
		snake->Dibujar();
		Sleep(100);
	}
}

bool Juego::Fin()
{
	// Si la cabeza de la serpiente choca con los límites del marco
	if(snake->Get_Casilla(0).Get_X() == ANCHO - 1 || snake->Get_Casilla(0).Get_X() == 0
	   || snake->Get_Casilla(0).Get_Y() == ALTO - 1 || snake->Get_Casilla(0).Get_Y() == 0)
	{
		Funciones::Goto_XY(ALTO, ANCHO / 7);
		std::cout << "******* GAME OVER *********";
		//return Otra_Partida();
		game_over = true;
	}
	// Si se pulsa la tecla ESCAPE
	char tecla_fin = getch();
	if(tecla_fin == ESCAPE)
	{
		Funciones::Goto_XY(ALTO / 2, ANCHO / 7);
		std::cout << "******** HAS PULSADO 'ESCAPE' ********";
		//return Otra_Partida();
		game_over = true;
	}
	// Si la cabeza de la serpiente choca con alguna parte de su cuerpo
	for(int i = 1; i < snake->Get_Partes_Cuerpo(); i++)
	{
		if(snake->Get_Casilla(0).Get_X() == snake->Get_Casilla(i).Get_X()
		   && snake->Get_Casilla(0).Get_Y() == snake->Get_Casilla(i).Get_Y())
		{
			Funciones::Goto_XY(ALTO, ANCHO / 7);
			std::cout << "******* GAME OVER *********";
			//return Otra_Partida();
			game_over = true;
		}
	}
	return game_over;
}

void Juego::Jugar()
{
	Funciones::No_Cursor();
	while(!Fin())
	{
		Actualizar();
	}
}

void Juego::Info_Teclas()
{
	Funciones::Goto_XY(ANCHO + 3, 2);
	std::cout << " Arriba    : Cursor ARRIBA";
	Funciones::Goto_XY(ANCHO + 3, 3);
	std::cout << " Abajo     : Cursor ABAJO";
	Funciones::Goto_XY(ANCHO + 3, 4);
	std::cout << " Izquierda : Cursor IZQUIERDA";
	Funciones::Goto_XY(ANCHO + 3, 5);
	std::cout << " Derecha   : Cursor DERECHA";
	Funciones::Goto_XY(ANCHO + 3, 6);
	std::cout << " Salir     : ESCAPE";
}
