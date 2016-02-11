#include "MovableObject.h"
#include "EntityStates.h"

MovableObject::MovableObject(const sf::Texture& texture, const sf::Vector2f& position)
	: GameObject(texture, position)
{
	hasGoal = false;
	isMoving = false;
	fsm = new StateMachine<MovableObject>(this);
	timeStandingStill = 0.0f;
	maxTimeStandingStill = 5.0f;
}

MovableObject::~MovableObject()
{

}

void MovableObject::Update(float delta)
{
	fsm->Update();

	if (isMoving)
	{
		if (hasGoal && VectorDistance(getPosition(), goal) > 2.0f)
		{
			move(DirectionBetween(getPosition(), goal) * delta * 10.0f);
		}
		else
		{
			hasGoal = false;
			fsm->ChangeState(Idle::Instance());
		}
	}
	else
	{
		timeStandingStill += delta;
	}
}

void MovableObject::SetGoal(const sf::Vector2f& newGoal)
{
	goal = newGoal;
	hasGoal = true;
	timeStandingStill = 0.0f;

	if (!fsm->IsInState<MovingToTarget>())
		fsm->ChangeState(MovingToTarget::Instance());
}

void MovableObject::SetIsMoving(bool isMoving)
{
	this->isMoving = isMoving;
}

sf::Vector2f MovableObject::GetClosePosition(float radius)
{
	sf::Vector2f position;
	position.x = RandomFloat(-radius, radius);
	position.y = RandomFloat(-radius, radius);
	position += getPosition();
	return position;
}