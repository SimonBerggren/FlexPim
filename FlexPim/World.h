#pragma once
#include "SFML/Graphics.hpp"
#include "WorldObjects.h"
#include "PlayerController.h"
#include "GameObject.h"
#include "Assets.h"
#include "Player.h"

class World
{
	sf::RenderWindow* window;
	sf::Sprite background;
	PlayerController* controller;
	Player* player;
	std::vector<GameObject*> gameObjects;
public:
	World(sf::RenderWindow* window);
	~World();
	void Update(float delta);
	void Draw();

	int GetWidth() { return background.getTexture()->getSize().x; }
	int GetHeight() { return background.getTexture()->getSize().y; }
};