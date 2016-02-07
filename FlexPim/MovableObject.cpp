#include "MovableObject.h"

MovableObject::MovableObject(const sf::Texture& texture, const sf::Vector2f & position)
	: GameObject(texture, position)
{
	hasGoal = false;
}

MovableObject::~MovableObject()
{

}

void MovableObject::Update(float delta)
{
	if (isMoving && hasGoal)
	{
		if (VectorDistance(getPosition(), goal) > 2)
			move(DirectionBetween(getPosition(), goal) * delta);
		else
			hasGoal = false;
	}
}

void MovableObject::SetNewGoal(const sf::Vector2f & newGoal)
{
	goal = newGoal;
	hasGoal = true;
}

void MovableObject::SetIsMoving(bool isMoving)
{
	isMoving = isMoving;
}