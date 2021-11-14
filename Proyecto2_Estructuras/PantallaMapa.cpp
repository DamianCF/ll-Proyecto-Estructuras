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
	PantallaPrincipal->draw(*basePantalla);
	PantallaPrincipal->display();

	while (PantallaPrincipal->isOpen())
	{
		posicionMouse();
		ejecutarEventos();
		//dibujar();
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
	std::string input_text;

	while (PantallaPrincipal->pollEvent(*evento))
	{
		PantallaPrincipal->draw(*basePantalla);

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

		if (evento->type == sf::Event::EventType::TextEntered) {
			if (std::isprint(evento->text.unicode))
				input_text += evento->text.unicode;
			cout << input_text;
		}

		if (evento->type == Event::MouseButtonPressed) 
		{
			if (Mouse::isButtonPressed(Mouse::Left)) {
				
				Tnodo = new Texture();
				Snodo = new Sprite;

				Tnodo->loadFromFile("resource/nodo1.png");
				Snodo->setTexture(*Tnodo);

				Snodo->setPosition(Vector2f(posicionM));
				Snodo->setScale(30.f / Snodo->getTexture()->getSize().x, 30.f / Snodo->getTexture()->getSize().y);

				PantallaPrincipal->draw(*Snodo);
				
				cout << posicionM.x << endl;
				cout << posicionM.y << endl;

				sf::Vertex line[] =
				{
					sf::Vertex(sf::Vector2f(10, 10)),
					sf::Vertex(sf::Vector2f(posicionM.x, posicionM.y))
				};PantallaPrincipal->draw(line, 2, sf::Lines);
			}

			PantallaPrincipal->display();
		}
	}
}

void PantallaMapa::posicionMouse() 
{
	posicionM = Mouse::getPosition(*PantallaPrincipal);
	posicionM = (Vector2i)PantallaPrincipal->mapPixelToCoords(posicionM);
}