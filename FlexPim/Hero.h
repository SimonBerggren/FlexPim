#pragma once
#include "MovableObject.h"
#include "Assets.h"

class Hero : public MovableObject
{
public:
	Hero(const sf::Vector2f& position);
	virtual ~Hero();

	virtual void Update(float delta) override;
};