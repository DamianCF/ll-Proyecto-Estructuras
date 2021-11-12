#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "PantallaMapa.h"

using namespace sf;
using namespace std;

#define Max_menu 5

class Menu {
private:

	int MenuSeleccionado;
	int fps;//cantidad de frames por segundo en que se actualiza la pantalla

	RenderWindow* menuPrincipal;//ventada que almacena el menu principal de la aplicacion
	Texture* texturaFondo;
	Sprite* basePantalla;
	Event* evento;

	Font* fuente;
	Text vectorBotones[Max_menu];

	PantallaMapa* Mapa;

	SoundBuffer buffer;
	Sound click;
public:
	Menu(int ancho, int alto, string titulo);
	~Menu();
	void gameloop();
	void dibujar();
	void ejecutarEventos();
	void MoverArriba();
	void Moverabajo();

	int MenuPressed()
	{
		return MenuSeleccionado;
	}
};