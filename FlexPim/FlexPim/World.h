#pragma once
#include "Assets.h"
#include "Player.h"

class World
{
	sf::Sprite background;
	Player* player;
public:
	World();
	~World();
	void Update(float delta);
	void Draw(sf::RenderWindow* window);

	int GetWidth() { return background.getTexture()->getSize().x; }
	int GetHeight() { return background.getTexture()->getSize().y; }
};