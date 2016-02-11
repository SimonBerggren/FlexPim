#pragma once
#include <iostream>
#include "MovableObject.h"
#include "State.h"

class Idle : public State<MovableObject>
{
	Idle() { }
	Idle(const Idle&) = delete;
	Idle& operator=(const Idle&) = delete;

public:
	static Idle* Instance();

	virtual void Enter(MovableObject* owner) override;
	virtual void Execute(MovableObject* owner) override;
	virtual void Exit(MovableObject* owner) override;
};

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

class AttackingTarget : public State<MovableObject>
{
	AttackingTarget() { }
	AttackingTarget(const MovingToTarget&) = delete;
	AttackingTarget& operator=(const MovingToTarget&) = delete;

public:
	static AttackingTarget* Instance();

	virtual void Enter(MovableObject* owner) override;
	virtual void Execute(MovableObject* owner) override;
	virtual void Exit(MovableObject* owner) override;
};