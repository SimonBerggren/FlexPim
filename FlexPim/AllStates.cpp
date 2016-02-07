#include "AllStates.h"

MovingToTarget * MovingToTarget::Instance()
{
	static MovingToTarget instance;
	return &instance;
}

void MovingToTarget::Enter(MovableObject * owner)
{
	owner->SetIsMoving(true);
	std::cout << "Started moving to target." << std::endl;
}

void MovingToTarget::Execute(MovableObject * owner)
{
	
}

void MovingToTarget::Exit(MovableObject * owner)
{
	owner->SetIsMoving(false);
	std::cout << "Stopped moving to target." << std::endl;
}