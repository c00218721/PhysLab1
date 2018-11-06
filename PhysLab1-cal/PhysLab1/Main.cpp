//author callum lynch

#ifdef _DEBUG  
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Go Physics!!");

	sf::CircleShape shape(0.5f);
	sf::RectangleShape ground(sf::Vector2f(800,800));


	shape.setFillColor(sf::Color::Green);
	ground.setFillColor(sf::Color::Blue);

	sf::Vector2f velocity(0, 0);
	sf::Vector2f position(400, 400);
	sf::Vector2f gPos(0, 600);

	sf::Vector2f gravity(0.0f, 9.8f);



	sf::Clock clock;

	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	clock.restart();

	while (window.isOpen())
	{

		//read keyboard inout
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();
		//update every 60th of a second
		if (timeSinceLastUpdate > timePerFrame)
		{


			window.clear();

			// update position and velocity here using equations in lab sheet using timeChange as  timeSinceLastUpdate.asSeconds().










			//update shape on screen
			shape.setPosition(position);
			ground.setPosition(gPos);

			window.draw(shape);
			window.draw(ground);

			window.display();
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
	return 0;
}
