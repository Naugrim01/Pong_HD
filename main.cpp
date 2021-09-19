//Libraries
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
	if (font.loadFromFile("Data/arial.ttf") == 0) //Safe way to load font
	{
		return 1;
	}

		//Images
		sf::Texture tex_pad; //Pad image/texutre
	sf::Texture tex_ball; //Ball texture
	sf::Texture tex_background; //Background texture

	//Load the 3 textures
	if (tex_pad.loadFromFile("Data/pad.png") == false)
	{
		return -1;
	}

	if (tex_ball.loadFromFile("Data/ball.png") == false)
	{
		return -1;
	}

	if (tex_background.loadFromFile("Data/background.png") == false)
	{
		return -1;
	}

	//Sounds
	sf::SoundBuffer buff_hit; //Hit sound

	//Load the sound
	if (buff_hit.loadFromFile("Data/hit.wav") == false)
	{
		return -1;
	}

	//States

	//Variables

	//Shapes

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

		window.display();
	}
	///////////



	//Close the program
	return 0;
}