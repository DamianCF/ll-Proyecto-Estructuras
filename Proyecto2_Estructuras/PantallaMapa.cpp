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
	
	grafo = new Grafo();
	

	evento = new Event;
	gameloop();
}

void PantallaMapa::gameloop()
{
	grafo->iniciar(5);
	PantallaPrincipal->draw(*basePantalla);
	PantallaPrincipal->display();

	while (PantallaPrincipal->isOpen())
	{
		posicionMouse();
		ejecutarEventos();
		
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
	std::string input_text;
	sf::CircleShape circulo(20);
	circulo.setFillColor(sf::Color::Black);

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
			if (evento->key.code == Keyboard::M)
			{
				grafo->mostrarGrafo();
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

				
					cout << posicionM.x << endl;
					cout << posicionM.y << endl;

					
					grafo->insertarNodo(posicionM.x, posicionM.y);
					ver();

				PantallaPrincipal->display();//mostramos los cambios del evento
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
					grafo->dijkstra(0, 4, 0);
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
		}
	}
}

void PantallaMapa::posicionMouse() 
{
	posicionM = Mouse::getPosition(*PantallaPrincipal);
	posicionM = (Vector2i)PantallaPrincipal->mapPixelToCoords(posicionM);
}

void PantallaMapa::ver()
{
	g = grafo->getRaiz();
	sf::CircleShape circulo(20);
	sf::Text etiq;
	sf::Text peso;
	sf::Font Fuente;

	
	Fuente.loadFromFile("fonts/PressStart2P-Regular.ttf");

	circulo.setFillColor(sf::Color::Black);

	int x;
	int y;

	int xx;
	int yy;

	while (g != NULL)
	{
		x = g->getCoorx();
		y = g->getCoory();

		if (g->getSigNodo() != NULL) {
			xx = g->getSigNodo()->getCoorx();
			yy = g->getSigNodo()->getCoory();
			
			int p = g->getAristaADY()->getPeso();

			//string num_cstr(STRING(p));
			string num_str1(std::to_string(p));

			peso.setString(num_str1);
			peso.setFont(Fuente);
			peso.setCharacterSize(15);
			peso.setPosition(Vector2f((x+xx)/2,((y+yy)/2)+10));
			PantallaPrincipal->draw(peso);

			//prueba para crear una linea
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(x, y)),
				sf::Vertex(sf::Vector2f(xx, yy))
			}; PantallaPrincipal->draw(line, 2, sf::Lines);
		}
		
		circulo.setPosition(x - 15 ,y - 15 );
		PantallaPrincipal->draw(circulo);
		
		etiq.setString(g->getNombreNodo());
		etiq.setFont(Fuente);
		etiq.setCharacterSize(15);
		etiq.setPosition(Vector2f(x-1, y-2));
		PantallaPrincipal->draw(etiq);

		g = g->getSigNodo();
	}
}