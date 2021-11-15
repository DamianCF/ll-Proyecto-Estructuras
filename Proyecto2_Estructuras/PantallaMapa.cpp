#include "PantallaMapa.h"
#include "Menu.h"

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
	//basePantalla->setScale(((float)PantallaPrincipal->getSize().x / basePantalla->getTexture()->getSize().x), ((float)PantallaPrincipal->getSize().y / basePantalla->getTexture()->getSize().y));

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

		if (evento->type == sf::Event::EventType::TextEntered) {//este evento capta las teclas que se presionan
			if (std::isprint(evento->text.unicode))
				input_text += evento->text.unicode;
			cout << input_text;
		}

		if (evento->type == Event::MouseButtonPressed and Mouse::isButtonPressed(Mouse::Left))
		{
			//creacion de nodos dentro del los mapa
			if (posicionM.x < 1010) {

					Tnodo = new Texture();
					Snodo = new Sprite;

					Tnodo->loadFromFile("resource/nodo1.png");
					Snodo->setTexture(*Tnodo);

					Snodo->setPosition(Vector2f(posicionM));

					PantallaPrincipal->draw(*Snodo);//se dibuja el nodo en pantalla

					cout << posicionM.x << endl;
					cout << posicionM.y << endl;

					//prueba para crear una linea
					sf::Vertex line[] =
					{
						sf::Vertex(sf::Vector2f(10, 10)),
						sf::Vertex(sf::Vector2f(posicionM.x, posicionM.y))
					}; PantallaPrincipal->draw(line, 2, sf::Lines);

			}

			//control de botones
			if (posicionM.x > 1010) {

				//Limpiar
				if ((posicionM.x > 1150 and posicionM.x < 1400) and (posicionM.y > 210 and posicionM.y < 280)) {
					cout << "Limpiar" << endl;
				}
				//Guardar
				if ((posicionM.x > 1150 and posicionM.x < 1400) and (posicionM.y > 300 and posicionM.y < 370)) {
					cout << "Guardar" << endl;
				}

				//Dijkstra
				if ((posicionM.x>1150 and posicionM.x <1400) and (posicionM.y>540 and posicionM.y<610)) {
					cout << "Dijkstra"<<endl;
				}

				//Warshall
				if ((posicionM.x > 1150 and posicionM.x < 1400) and (posicionM.y > 624 and posicionM.y < 690)) {
					cout << "Warshall" << endl;
				}

				//Primm
				if ((posicionM.x > 1150 and posicionM.x < 1400) and (posicionM.y > 705 and posicionM.y < 775)) {
					cout << "Primm" << endl;
				}

				//Kruskal
				if ((posicionM.x > 1150 and posicionM.x < 1400) and (posicionM.y > 790 and posicionM.y < 855)) {
					cout << "Kruskal" << endl;
				}

				//Menu
				if ((posicionM.x > 1069 and posicionM.x < 1500) and (posicionM.y > 910 and posicionM.y < 985)) {
					PantallaPrincipal->close();
					Menu* partida;
					partida = new Menu(960, 540, "SOKOBAN");
					cout << "Menu" << endl;
				}

			}

			PantallaPrincipal->display();//mostramos los cambios del evento
		}
	}
}

void PantallaMapa::posicionMouse() 
{
	posicionM = Mouse::getPosition(*PantallaPrincipal);
	posicionM = (Vector2i)PantallaPrincipal->mapPixelToCoords(posicionM);
}