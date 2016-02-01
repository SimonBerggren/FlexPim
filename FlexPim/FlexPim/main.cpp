#include <iostream>
#include "World.h"
#include "Utils.h"

#define WINDOW_TITLE "FlexPim"

sf::RenderWindow *window;
sf::View* camera;
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
	window = new sf::RenderWindow(desktop, WINDOW_TITLE, sf::Style::None);
	camera = new sf::View(sf::Vector2f(windowWidth, windowHeight), sf::Vector2f(windowWidth, windowHeight));
	window->setView(*camera);

	sf::Clock clock;
	float lastUpdate = 0;
	float updateFrequency = (1.0f / 60.0f);
	float delta;

	world = new World();

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
				if (sf::Mouse::getPosition(*window).x > (windowWidth - xoffset))
					camera->move(cameraMoveSpeed, 0);
				else if (sf::Mouse::getPosition(*window).x < xoffset)
					camera->move(-cameraMoveSpeed, 0);
				if (sf::Mouse::getPosition(*window).y >(windowHeight - yoffset))
					camera->move(0, cameraMoveSpeed);
				else if (sf::Mouse::getPosition(*window).y < yoffset)
					camera->move(0, -cameraMoveSpeed);

				sf::Vector2f min = camera->getSize() / 2.0f;
				sf::Vector2f max = sf::Vector2f(world->GetWidth() - (camera->getSize().x / 2.0f),
															  world->GetHeight() - (camera->getSize().y / 2.0f));


				camera->setCenter(sf::Vector2f(Clamp(camera->getCenter().x, min.x, max.x), 
														       Clamp(camera->getCenter().y, min.y, max.y)));
					window->setView(*camera);
			}
		}

		window->clear();

		// draw logic 
		world->Draw(window);

		window->display();
	}

	delete window;
	window = nullptr;

	return 0;
}