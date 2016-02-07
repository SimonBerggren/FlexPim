#pragma once
#include "SFML/Graphics.hpp"
#include "Assets.h"
#include "Utilities.h"

class HUD : sf::Sprite
{
	int& gold;
	int& buildings;
	int& units;

	sf::Text goldText;
	sf::Text buildingsText;
	sf::Text unitsText;
public:
	HUD(int& gold, int& buildings, int& units);
	~HUD();

	void Draw(sf::RenderWindow* window);
};