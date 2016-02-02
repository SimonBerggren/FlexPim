#include "Hero.h"
#include <iostream>
Hero::Hero(const sf::Vector2f& position)
	: GameObject(*PlayerTexture(), position)
{

}

void Hero::Update(float delta)
{
	GameObject::Update(delta);
}

Hero::~Hero()
{

}