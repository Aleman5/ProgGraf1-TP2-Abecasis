#include"SFML\Audio.hpp"
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"

//using namespace sf;

void main() 
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Game's Working");

	while (window.isOpen())
	{
		sf::Event event;
		
		if (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

				default:
					break;
			}
		}

		window.clear();
		window.display();
	}
}