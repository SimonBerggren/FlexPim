#include "Hero.h"
#include <iostream>
Hero::Hero()
	: GameObject(*PlayerTexture())
{

}

void Hero::Update(float delta)
{
	GameObject::Update(delta);
}

Hero::~Hero()
{

}