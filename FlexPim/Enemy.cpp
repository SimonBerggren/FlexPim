#include "Enemy.h"

Enemy::Enemy()
	: MovableObject(*PlayerTexture(), sf::Vector2f(0.0f, 0.0f))
{
}

Enemy::~Enemy()
{
}