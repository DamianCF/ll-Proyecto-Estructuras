#include "PantallaMapa.h"

PantallaMapa::~PantallaMapa()
{

}

PantallaMapa::PantallaMapa(int ancho, int alto, string titulo)
{
	fps = 60;
	PantallaPrincipal = new RenderWindow(VideoMode(ancho, alto), titulo);//creamos la pantalla del menu principal
	PantallaPrincipal->setFramerateLimit(fps);//se limita los fps a la pantalla

	texturaFondo = new Texture;// se crea la textura
	basePantalla = new Sprite;// se crea la base de la pantalla
	texturaFondo->loadFromFile("resource/mapa.jpg");
	basePantalla->setTexture(*texturaFondo);
	basePantalla->setScale(((float)PantallaPrincipal->getSize().x / basePantalla->getTexture()->getSize().x), ((float)PantallaPrincipal->getSize().y / basePantalla->getTexture()->getSize().y));

	fuente = new Font();
	fuente->loadFromFile("fonts/PressStart2P-Regular.ttf");

	evento = new Event;
	gameloop();
}

void PantallaMapa::gameloop()
{
	while (PantallaPrincipal->isOpen())
	{
		ejecutarEventos();
		dibujar();
	}
}

void PantallaMapa::dibujar()
{
	PantallaPrincipal->clear();
	PantallaPrincipal->draw(*basePantalla);
	PantallaPrincipal->display();
}

void PantallaMapa::ejecutarEventos()
{
	while (PantallaPrincipal->pollEvent(*evento))
	{
		if (evento->type == Event::Closed)
		{
			PantallaPrincipal->close();
			exit(1);
		}
		if (evento->type == Event::KeyReleased)
		{
			if (evento->key.code == Keyboard::Up)
			{
				cout << evento->key.code;
				break;
			}
			if (evento->key.code == Keyboard::Down)
			{
				cout << evento->key.code;
				break;
			}
		}
	}
}