#include "Enemy.h"

Enemy::Enemy()
	: GameObject(*PlayerTexture(), sf::Vector2f(0.0f, 0.0f))
{
}

Enemy::~Enemy()
{
}