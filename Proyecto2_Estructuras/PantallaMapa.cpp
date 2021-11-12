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
		posicionMouse();
		ejecutarEventos();
		dibujar();
	}
}

void PantallaMapa::dibujar()
{
	PantallaPrincipal->clear();
	PantallaPrincipal->draw(*basePantalla);
	//PantallaPrincipal->draw(*Snodo);
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
		if (evento->type == Event::MouseButtonPressed) 
		{
			if (Mouse::isButtonPressed(Mouse::Left)) {
				PantallaPrincipal->clear();
				texturaFondo->loadFromFile("resource/mapa.jpg");
				basePantalla->setTexture(*texturaFondo);
				basePantalla->setScale(((float)PantallaPrincipal->getSize().x / basePantalla->getTexture()->getSize().x), ((float)PantallaPrincipal->getSize().y / basePantalla->getTexture()->getSize().y));
				PantallaPrincipal->draw(*basePantalla);

				Tnodo = new Texture();
				Snodo = new Sprite;

				Tnodo->loadFromFile("resource/nodo1.png");
				Snodo->setTexture(*Tnodo);

				Snodo->setPosition(Vector2f(posicionM));
				Snodo->setScale(100.f / Snodo->getTexture()->getSize().x, 100.f / Snodo->getTexture()->getSize().y);

				PantallaPrincipal->draw(*Snodo);
				PantallaPrincipal->display();

				cout << posicionM.x << endl;
				cout << posicionM.y << endl;
			}
		}
	}
}

void PantallaMapa::posicionMouse() 
{
	posicionM = Mouse::getPosition(*PantallaPrincipal);
	posicionM = (Vector2i)PantallaPrincipal->mapPixelToCoords(posicionM);
}