#include "GlobalStates.h"

StrollingAround * StrollingAround::Instance()
{
	static StrollingAround instance;
	return &instance;
}

void StrollingAround::Enter(MovableObject * owner)
{
	std::cout << "Entered strolling around" << std::endl;
}

void StrollingAround::Execute(MovableObject * owner)
{
	// if we see an enemy, move to it and attack it
	if (!owner->GetAggroObj())
	{
		owner->SetAggroObj(WorldObjects::FindObject(owner->getPosition(), owner->GetAggroRange()));
		if (owner->GetAggroObj())
		{
			if (!(VectorDistance(owner->getPosition(), owner->GetAggroObj()->getPosition()) <= (owner->Diagonal() + owner->GetAggroObj()->Diagonal())))
				owner->SetGoal(owner->GetAggroObj()->getPosition());
			else
				owner->GetFSM()->ChangeState(AttackingTarget::Instance());
		}
	}

	// if we are standing still, move
	if (owner->GetFSM()->IsInState<Idle>())
	{
		if (!owner->IsMoving() && owner->GetTimeStandingStill() >= owner->GetMaxTimeStandingStill())
		{
			owner->SetGoal(owner->GetClosePosition(500.0f));
		}
	}
}

void StrollingAround::Exit(MovableObject * owner)
{
	std::cout << "Exited strolling around" << std::endl;
}

HasAggro * HasAggro::Instance()
{
	return nullptr;
}

void HasAggro::Enter(MovableObject * owner)
{
}

void HasAggro::Execute(MovableObject * owner)
{
}

void HasAggro::Exit(MovableObject * owner)
{
}
