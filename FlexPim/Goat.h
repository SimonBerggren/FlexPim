#pragma once
#include "Animal.h"

class Goat : public Animal
{
public:
	Goat(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~Goat();
};