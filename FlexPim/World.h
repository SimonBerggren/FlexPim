#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerController.h"
#include "MovableObject.h"
#include "WorldObjects.h"
#include "GameObject.h"
#include "EntityStates.h"
#include "Assets.h"
#include "Player.h"
#include "Tile.h"
#include "Goat.h"

class World
{
	sf::RenderWindow* window;
	sf::Sprite background;
	PlayerController* controller;
	Player* player;
	std::vector<GameObject*> gameObjects;
	Tile<>* tiles;
	int tileCount;
	int tileSize;
public:
	World(sf::RenderWindow* window);
	~World();
	void Update(float delta);
	void Draw();

	int GetWidth() { return background.getTexture()->getSize().x; }
	int GetHeight() { return background.getTexture()->getSize().y; }

	Goat* goat;
};