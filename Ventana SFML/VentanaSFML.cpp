#include "SFML\Window.hpp"
#include "SFML\Window\Window.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>
#include <string>


void main(){
	sf::Texture texture;
	texture.loadFromFile("sprite.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(350,0);
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(100, 250, 50));
	sf::RenderWindow window(sf::VideoMode(800, 600), "NotAVirus.exe");
	while (window.isOpen())
	{
		shape.move(0.01,0);
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(sprite);
		window.display();
	}
}