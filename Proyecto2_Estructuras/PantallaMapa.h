#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>
#include <locale> 
#include "Grafo.h"

using namespace sf;
using namespace std;

#define Max_menu 5
#define STRING(num) #num

class PantallaMapa {
private:
	int fps;//cantidad de frames por segundo en que se actualiza la pantalla

	RenderWindow* PantallaPrincipal;//ventada que almacena el mapa principal de la aplicacion
	Texture* texturaFondo;
	Sprite* basePantalla;
	Event* evento;

	Font* fuente;
	Text vectorBotones[Max_menu];

	Text mensaje;

	Vector2i posicionM;

	SoundBuffer buffer;
	Sound click;

	Grafo* grafo;
	Grafo* g;

	int tamano;
	int cont;

public:
	PantallaMapa(int ancho, int alto, string titulo);
	~PantallaMapa();
	void gameloop();
	void dibujar();
	void ver();
	void ver2(char);
	void ejecutarEventos();
	void posicionMouse();
};