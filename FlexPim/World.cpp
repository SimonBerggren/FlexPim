#include "World.h"

World::World(sf::RenderWindow* window)
	: window(window)
{
	background.setTexture(*WorldTexture());
	controller = new PlayerController();
	player = new Player(window);
	goat = new Goat(*GoatTexture(), sf::Vector2f(20.0f, 20.0f));
	WorldObjects::AddObject(goat);

	tileSize = 30;
	tileCount = (background.getTexture()->getSize().x / tileSize) * (background.getTexture()->getSize().y / tileSize);
	int windowSize = background.getTexture()->getSize().x * background.getTexture()->getSize().y;
	int tilesX = (background.getTexture()->getSize().x / tileSize);
	int tilesY = (background.getTexture()->getSize().y / tileSize);
	tiles = new Tile<TileType::Walkable>[tileCount];

	for (int y = 0; y < tilesY; ++y)
	{
		for (int x = 0; x < tilesX; ++x)
		{
			tiles[x + tilesX * y].setSize(sf::Vector2f(tileSize, tileSize));
			tiles[x + tilesX * y].setPosition(x * tileSize, y * tileSize);
			tiles[x + tilesX * y].setFillColor(sf::Color::Transparent);
			tiles[x + tilesX * y].setOutlineColor(sf::Color::Green);
			tiles[x + tilesX * y].setOutlineThickness(2.0f);

			if (WorldObjects::InterSects(tiles[x + tilesX * y]))
				tiles[x + tilesX * y].SetType(TileType::NonWalkable);
		}
	}
}

World::~World()
{
	delete[] tiles;
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
				((MovableObject*)player->selected)->SetGoal(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
	}
}

void World::Draw()
{
	window->draw(background);

	for (auto obj = WorldObjects::objects.begin(); obj != WorldObjects::objects.end(); ++obj)
	{
		(*obj)->Draw(window);
	}
	//for (int i = 0; i < tileCount; i++)
	//	window->draw(tiles[i]);

	player->Draw(window);
}