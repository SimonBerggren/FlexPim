#include "EntityStates.h"
#include "BuildingStates.h"

/////////////////////////////// IDLE ///////////////////////////////

Idle * Idle::Instance()
{
	static Idle instance;
	return &instance;
}

void Idle::Enter(MovableObject * owner)
{
	std::cout << "Entered idle state" << std::endl;
}

void Idle::Execute(MovableObject * owner)
{

}

void Idle::Exit(MovableObject * owner)
{
	std::cout << "Exited idle state" << std::endl;
}

/////////////////////////////// MOVING TO TARGET ///////////////////////////////

MovingToTarget * MovingToTarget::Instance()
{
	static MovingToTarget instance;
	return &instance;
}

void MovingToTarget::Enter(MovableObject * owner)
{
	owner->SetIsMoving(true);
	std::cout << "Entered moving to target." << std::endl;
}

void MovingToTarget::Execute(MovableObject * owner)
{

}

void MovingToTarget::Exit(MovableObject * owner)
{
	owner->SetIsMoving(false);
	std::cout << "Exited moving to target." << std::endl;
}

/////////////////////////////// ATTACKING TARGET ///////////////////////////////

AttackingTarget * AttackingTarget::Instance()
{
	static AttackingTarget instance;
	return &instance;
}

void AttackingTarget::Enter(MovableObject * owner)
{
	std::cout << "Entered attacking state" << std::endl;
}

void AttackingTarget::Execute(MovableObject * owner)
{
	if (!owner->IsOnCooldown())
	{
		owner->GetAggroObj()->DoDamage(2.0f);
		if (owner->GetAggroObj()->IsDead())
		{
			WorldObjects::RemoveObject(owner->GetAggroObj());
			delete owner->GetAggroObj();
			owner->aggroObj = nullptr;
		}
	}
}

void AttackingTarget::Exit(MovableObject * owner)
{
	std::cout << "Exited attacking state" << std::endl;
}