#pragma once
#include "MovableObject.h"

class Goat : public MovableObject
{
public:
	Goat(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~Goat();
	virtual void Update(float delta) override;
};