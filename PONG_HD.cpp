#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "PONG_HD");
	while (window.isOpen())
	{
		sf::Event event;
		//main game loop
		while (window.pollEvent(event))
		{
			//process events
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			//Rendering part of the main game loop
			
			window.clear();

			//Draw things

			window.display();
		}
	}
	return 0;
}