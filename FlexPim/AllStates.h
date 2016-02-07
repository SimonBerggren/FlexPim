#pragma once
#include <iostream>
#include "MovableObject.h"
#include "State.h"

class MovingToTarget : public State<MovableObject>
{
	MovingToTarget() { }
	MovingToTarget(const MovingToTarget&) = delete;
	MovingToTarget& operator=(const MovingToTarget&) = delete;

public:
	static MovingToTarget* Instance();

	virtual void Enter(MovableObject* owner) override;
	virtual void Execute(MovableObject* owner) override;
	virtual void Exit(MovableObject* owner) override;
};