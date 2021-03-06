#pragma once
#include "WorldObjects.h"
#include "EntityStates.h"
#include "State.h"

class StrollingAround : public State<MovableObject>
{
	StrollingAround() { }
	StrollingAround(const StrollingAround&) = delete;
	StrollingAround& operator=(const StrollingAround&) = delete;

public:
	static StrollingAround* Instance();

	virtual void Enter(MovableObject* owner) override;
	virtual void Execute(MovableObject* owner) override;
	virtual void Exit(MovableObject* owner) override;
};

class HasAggro : public State<MovableObject>
{
	HasAggro() { }
	HasAggro(const HasAggro&) = delete;
	HasAggro& operator=(const HasAggro&) = delete;

public:
	static HasAggro* Instance();

	virtual void Enter(MovableObject* owner) override;
	virtual void Execute(MovableObject* owner) override;
	virtual void Exit(MovableObject* owner) override;
};