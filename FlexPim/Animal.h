#pragma once
#include "MovableObject.h"
#include "GlobalStates.h"

class Animal : public MovableObject
{
public:
	Animal(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~Animal();
};