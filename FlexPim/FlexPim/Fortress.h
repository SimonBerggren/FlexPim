#pragma once
#include "Building.h"
#include "Assets.h"

class Fortress : public  Building
{
public:
	Fortress(const sf::Vector2f& position);
	virtual  ~Fortress();
};