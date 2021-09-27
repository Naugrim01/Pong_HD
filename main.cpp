#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

//Global variables, functions, classes

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
	bool up = false;
	bool down = false;

	//Variables

	int yVelocityPad1 = 0;
	int xVelocityBall = -4;
	int yVelocityBall = -4;
	int yVelocityPad2 = 0;


	//Shapes
		//background
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1280, 720));
	background.setPosition(0, 0);
	background.setTexture(&tex_background);
		//pad1
	sf::RectangleShape pad1;
	pad1.setSize(sf::Vector2f(30, 120));
	pad1.setTexture(&tex_pad);
	pad1.setPosition(30, 200);

		//pad2
	sf::RectangleShape pad2;
	pad2.setSize(sf::Vector2f(30, 120));
	pad2.setTexture(&tex_pad);
	pad2.setPosition(1220, 400);

		//ball
	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(30, 30));
	ball.setTexture(&tex_ball);
	ball.setPosition(600, 300);
	
	
	//Game loop
	while (window.isOpen())
	{
		//EVENTS
		while (window.pollEvent(event))
		{
			//Event type is window closed
			if (event.type == sf::Event::Closed)
				window.close();

			// Key pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				up = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				down = true;
			}

			// Key released

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
			{
				up = false;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
			{
				down = false;
			}

		}

		//LOGIC

			//Pad1
		if (up == down)
		{
			yVelocityPad1 = 0;
		}
		else if (up == true)
		{
			yVelocityPad1 = -5;
		}
		else
		{
			yVelocityPad1 = 5;
		}

		pad1.move(0, yVelocityPad1);

				//Out of bounds check
		if (pad1.getPosition().y < 0)
		{
			pad1.setPosition(30, 0);
		}

		if (pad1.getPosition().y > 600)
		{
			pad1.setPosition(30, 600);
		}
		

			//Pad2
		if (ball.getPosition().y < pad2.getPosition().y)
		{
			yVelocityPad2 = -4;
		}

		if (ball.getPosition().y > pad2.getPosition().y)
		{
			yVelocityPad2 = 4;
		}

		pad2.move(0, yVelocityPad2);

		//Out of bounds check
		if (pad2.getPosition().y < 0)
		{
			pad2.setPosition(1220, 0);
		}

		if (pad2.getPosition().y > 600)
		{
			pad2.setPosition(1220, 600);
		}

			//Ball
		ball.move(xVelocityBall, yVelocityBall);
				//Out of bounds check
		if (ball.getPosition().y < 0)
		{
			yVelocityBall *= -1;
			hit.play();
		}

		if (ball.getPosition().y > 690)
		{
			yVelocityBall *= -1;
			hit.play();
		}

		if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds()) == true)
		{
			xVelocityBall *= -1;
			hit.play();
		}
		if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
		{
			xVelocityBall *= -1;
			hit.play();
		}

		//RENDERING
		window.clear();
		window.draw(background);
		window.draw(pad1);
		window.draw(pad2);
		window.draw(ball);
		window.display();
	}



	//Close the program
	return 0;
}