#include "World.h"

World::World(sf::RenderWindow* window)
	: window(window)
{
	background.setTexture(*WorldTexture());
	controller = new PlayerController();
	player = new Player(window);
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
				break;
			}
			else if (player->selected)
			{
				player->selected->Select(false);
				player->selected = nullptr;
			}
		}
		if (controller->RightClicked() && player->selected && dynamic_cast<MovableObject*>(player->selected))
			((MovableObject*)player->selected)->SetNewGoal(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
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