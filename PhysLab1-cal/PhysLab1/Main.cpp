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
#include <iostream>

int main()
{
	bool spacePressed = false;

	sf::RenderWindow window(sf::VideoMode(800, 800), "Go Physics!!");

	sf::CircleShape shape(.5f);
	sf::RectangleShape ground(sf::Vector2f(800,800));


	shape.setFillColor(sf::Color::Green);
	ground.setFillColor(sf::Color::Blue);

	sf::Vector2f velocity(0, 0);
	sf::Vector2f position(400, 400);
	sf::Vector2f gPos(0, 605.8);
	

	sf::Vector2f gravity(0.0f, 9.8f);

	sf::Vector2f impulse(0.0f, 20.0f);

	

	sf::Text maxHeightText;
	sf::Text predictedTime;
	sf::Font m_font;

	
	

	sf::Clock clock;

	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	float time = 1.0f / 60.0f;

	clock.restart();

	while (window.isOpen())
	{
		if (!m_font.loadFromFile("ariblk.ttf"))
		{
			std::cout << "error loading font" << std::endl;
		}
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
			
			position = position + velocity * time + 0.5f * gravity*(time * time);
			velocity = velocity + gravity * time;

			if (position.y > 605)
			{
				velocity.y = 0;
				position.y = 605;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && position.y > 604 && spacePressed == false)
			{

				velocity.y = -26;
				spacePressed = true;
			}

			//to stop the spamming of space to make it look like its bouncing
			if(spacePressed == true)
			{
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					spacePressed = false;
				}
			}



			float seconds = (2 * 26) / (9.8);
			

			float maxHeight = (26 * 26) / (2 * 9.8);

			predictedTime.setPosition(0, 0);
			predictedTime.setFont(m_font);
			predictedTime.setCharacterSize(15);
			predictedTime.setFillColor(sf::Color::White);
			predictedTime.setString(std::to_string(seconds));

			maxHeightText.setPosition(0, 40);
			maxHeightText.setFont(m_font);
			maxHeightText.setCharacterSize(15);
			maxHeightText.setFillColor(sf::Color::White);
			maxHeightText.setString(std::to_string(maxHeight));

		

 		
			


			//update shape on screen
			shape.setPosition(position);
			ground.setPosition(gPos);

			
			window.draw(ground);
			window.draw(shape);
			window.draw(predictedTime);
			window.draw(maxHeightText);




			window.display();
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
	return 0;
}
