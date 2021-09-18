#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "PONG_HD");

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		//main game loop
		while (window.pollEvent(event))
		{
			//Process events
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			//logic handling
			

			//Rendering part of the main game loop
			
			window.clear();

			//Draw things

			window.display();
		}
	}
	return 0;
}