#pragma once
#include "GameObject.h"

class Building : public GameObject
{
	Building();
public:
	Building(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~Building();
};