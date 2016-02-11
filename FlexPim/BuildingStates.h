#pragma once
#include "Building.h"
#include "State.h"

class ProducingHero : public State<Building>
{
	ProducingHero() { }
	ProducingHero(const ProducingHero&) = delete;
	ProducingHero& operator=(const ProducingHero&) = delete;

public:
	static ProducingHero* Instance();

	virtual void Enter(Building* owner) override;
	virtual void Execute(Building* owner) override;
	virtual void Exit(Building* owner) override;
};