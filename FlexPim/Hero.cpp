#include "Hero.h"
#include <iostream>
Hero::Hero(const sf::Vector2f& position)
	: MovableObject(*PlayerTexture(), position)
{

}

void Hero::Update(float delta)
{
	MovableObject::Update(delta);
}

Hero::~Hero()
{

}