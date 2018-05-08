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
	int speed = 10000;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Game's Working");

	sf::Texture texture;
	texture.loadFromFile("player.png");
	sf::Sprite spritePlayer;
	spritePlayer.setTexture(texture);

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time dt = deltaClock.restart();

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
					spritePlayer.move(0, -speed * dt.asSeconds());
					break;

				case sf::Keyboard::Down:
					spritePlayer.move(0, speed * dt.asSeconds());
					break;

				case sf::Keyboard::Right:
					spritePlayer.move(speed * dt.asSeconds(), 0);
					break;

				case sf::Keyboard::Left:
					spritePlayer.move(-speed * dt.asSeconds(), 0);
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