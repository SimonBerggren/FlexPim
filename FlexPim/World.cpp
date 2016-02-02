#include "World.h"

World::World(sf::RenderWindow* window)
{
	background.setTexture(*WorldTexture());
	this->window = window;
	player = new Player();
	controller = new PlayerController();
}

World::~World()
{
	delete player;
	delete controller;
}

void World::Update(float delta)
{
	player->Update(delta);

	for (auto obj = WorldObjects::objects.begin(); obj != WorldObjects::objects.end(); ++obj)
	{
		(*obj)->Update(delta);

		if (controller->LeftClicked())
		{
			GameObject* selected = WorldObjects::FindObject(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));

			if (selected)
			{
				if (player->selected)
					player->selected->Select(false);

				selected->Select(true);
				player->selected = selected;
			}
			else if(player->selected)
			{
				player->selected->Select(false);
				player->selected = nullptr;
			}
		}
		if (controller->RightClicked() && player->selected)
			player->selected->MoveTo(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
	}
}

void World::Draw()
{
	window->draw(background);

	for (auto obj = WorldObjects::objects.begin(); obj != WorldObjects::objects.end(); ++obj)
	{
		(*obj)->Draw(window);
	}

	player->Draw(window);
}