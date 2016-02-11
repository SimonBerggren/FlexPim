#pragma once
#include "GameObject.h"
#include "StateMachine.h"
#include "PathFinder.h"

class MovableObject : public GameObject
{
protected:
	bool playerOwned;
	bool hasGoal;
	bool isMoving;
	float timeStandingStill;
	float maxTimeStandingStill;
	PathFinder pathFinder;

	StateMachine<MovableObject>* fsm;

public:
	MovableObject(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~MovableObject();
	virtual void Update(float delta) override;
	void SetGoal(const sf::Vector2f& newGoal);
	void SetIsMoving(bool isMoving);

	StateMachine<MovableObject>* GetFSM() const { return fsm; }
	float GetTimeStandingStill() const { return timeStandingStill; }
	float GetMaxTimeStandingStill() const { return maxTimeStandingStill; }
	bool IsPlayerOwned() const { return playerOwned; }
	sf::Vector2f GetClosePosition(float radius);
};