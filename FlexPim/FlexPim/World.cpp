#include "World.h"

World::World()
{
	background.setTexture(*WorldTexture());
	player = new Player();
}

World::~World()
{
	delete player;
}

void World::Update(float delta)
{
	player->Update(delta);
}

void World::Draw(sf::RenderWindow * window)
{
	window->draw(background);
	player->Draw(window);
}