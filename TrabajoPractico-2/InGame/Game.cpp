#include"SFML\Audio.hpp"
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Graphics\Texture.hpp"

//using namespace sf;

void main() 
{
	int windowWidth = 640;
	int windowHeight = 480;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Game's Working");

	sf::Texture texture;
	texture.loadFromFile("player.png");
	sf::Sprite spritePlayer;
	spritePlayer.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		
		if (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					spritePlayer.move(0, -2);
					break;

				case sf::Keyboard::Down:
					spritePlayer.move(0, 2);
					break;

				case sf::Keyboard::Right:
					spritePlayer.move(0, 2);
					break;

				case sf::Keyboard::Left:
					spritePlayer.move(0, -2);
					break;

				case sf::Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}

				break;

			default:
				break;
			}
			
		}

		window.clear();
		window.draw(spritePlayer);
		window.display();
	}
}