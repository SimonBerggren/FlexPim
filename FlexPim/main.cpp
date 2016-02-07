#include <iostream>
#include "World.h"
#include "Utilities.h"

sf::RenderWindow *window;
World *world;

int windowWidth = 1920;
int windowHeight = 1080;
int xoffset = 50;
int yoffset = 50;
int cameraMoveSpeed = 10;

// main entry point
int main()
{
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "FlexPim", sf::Style::Default);
	sf::View view(sf::Vector2f(windowWidth, windowHeight), sf::Vector2f(windowWidth, windowHeight));

	sf::Clock clock;
	float lastUpdate = 0.0f;
	float updateFrequency = (1.0f / 60.0f);
	float delta;

	world = new World(window);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			// window events
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			default:
				break;
			}
		}

		delta = clock.restart().asSeconds();
		lastUpdate += delta;
		while (lastUpdate > updateFrequency)
		{
			lastUpdate -= updateFrequency;
			// update
			world->Update(delta);

			if (window->hasFocus())
			{
				if (sf::Mouse::getPosition(*window).x > (windowWidth - xoffset) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					view.move(cameraMoveSpeed, 0);
				else if (sf::Mouse::getPosition(*window).x < xoffset || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					view.move(-cameraMoveSpeed, 0);
				if (sf::Mouse::getPosition(*window).y >(windowHeight - yoffset) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					view.move(0, cameraMoveSpeed);
				else if (sf::Mouse::getPosition(*window).y < yoffset || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					view.move(0, -cameraMoveSpeed);

				sf::Vector2f min = view.getSize() / 2.0f;
				sf::Vector2f max = sf::Vector2f(world->GetWidth() - (view.getSize().x / 2.0f),
															  world->GetHeight() - (view.getSize().y / 2.0f));


				view.setCenter(sf::Vector2f(Clamp(view.getCenter().x, min.x, max.x), 
														       Clamp(view.getCenter().y, min.y, max.y)));
					window->setView(view);
			}
		}

		window->clear();

		// draw logic 
		world->Draw();

		window->display();
	}

	delete window;
	window = nullptr;

	return EXIT_SUCCESS;
}