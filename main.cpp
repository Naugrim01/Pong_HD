#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

//Glboal variables, functions, classes

//C++ program entry point
int main()
{
	//Creating the window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Game");

	//Settign the framerate limit to 60 FPS
	window.setFramerateLimit(60);

	window.setKeyRepeatEnabled(false);

	//Variable that keeps the game loop running
	bool play = true;

	//Event object holding all events
	sf::Event event;

	//Font
	sf::Font font;	//Font object
	if (font.loadFromFile("Data/LCD.otf") == false)
	{
		std::cout << "Font load filed\n";
		return 1;
	}

		//Images
	sf::Texture tex_pad; //Pad image/texutre
	sf::Texture tex_ball; //Ball texture
	sf::Texture tex_background; //Background texture

	//Load the textures
	if (tex_pad.loadFromFile("Data/pad.png") == false)
	{
		std::cout << "Pad texture load filed\n";
		return 2;
	}

	if (tex_ball.loadFromFile("Data/ball.png") == false)
	{
		std::cout << "Ball texture load filed\n";
		return 2;
	}

	if (tex_background.loadFromFile("Data/background.png") == false)
	{
		std::cout << "Background texture load filed\n";
		return 2;
	}



	//Sounds 
	sf::SoundBuffer buff_hit;
	sf::Sound hit;
	hit.setBuffer(buff_hit);

	if (buff_hit.loadFromFile("Data/po.wav") == false)
	{
		std::cout << "Hit sound failed\n";
		return 2;
	}

	//States

	//Variables

	//Shapes
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1280, 720));
	background.setPosition(0, 0);
	background.setTexture(&tex_background);
	//Game loop
	while (window.isOpen())
	{
		//EVENTS
		while (window.pollEvent(event))
		{
			//Event type is window closed
			if (event.type == sf::Event::Closed)
				window.close();

		}

		//LOGIC

		//RENDERING
		window.clear();
		window.draw(background);

		window.display();
	}



	//Close the program
	return 0;
}