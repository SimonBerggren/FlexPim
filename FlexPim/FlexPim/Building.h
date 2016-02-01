#pragma once
#include "GameObject.h"

class Building : public GameObject
{
	Building();
public:
	Building(const sf::Vector2f& position, const sf::Texture& texture);
	virtual ~Building();
};