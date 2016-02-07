#pragma once
#include "SFML/Graphics.hpp"
#include "Assets.h"

class BuildingHUD : public sf::Sprite
{
public:
	BuildingHUD();
	~BuildingHUD();
	void Draw(sf::RenderWindow* window);
};