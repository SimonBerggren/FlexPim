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
	if (owner->GetFSM()->IsInState<Idle>())
	{
		if (owner->GetTimeStandingStill() >= owner->GetMaxTimeStandingStill())
			owner->SetGoal(owner->GetClosePosition(200.0f));
	}
}

void StrollingAround::Exit(MovableObject * owner)
{
	std::cout << "Exited strolling around" << std::endl;
}