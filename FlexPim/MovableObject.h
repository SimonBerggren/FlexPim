#pragma once
#include "GameObject.h"
#include "StateMachine.h"
#include "WorldObjects.h"
#include "PathFinder.h"

class MovableObject : public GameObject
{
protected:
	bool playerOwned;
	bool hasGoal;
	bool isMoving;
	float timeStandingStill;
	float maxTimeStandingStill;
	float aggroRange;
	PathFinder pathFinder;

	StateMachine<MovableObject>* fsm;
	sf::Vector2f dir;
	sf::Vector2f normdir;


public:
	GameObject* aggroObj;
	sf::Clock standingStill;
	sf::Clock attackClock;
	MovableObject(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~MovableObject();
	virtual void Update(float delta) override;
	void SetGoal(const sf::Vector2f& newGoal);
	void SetIsMoving(bool isMoving);

	StateMachine<MovableObject>* GetFSM() const { return fsm; }
	float GetTimeStandingStill() const { return standingStill.getElapsedTime().asSeconds(); }
	float GetMaxTimeStandingStill() const { return maxTimeStandingStill; }
	bool IsPlayerOwned() const { return playerOwned; }
	bool IsMoving() const { return isMoving; }
	float GetAggroRange() const { return aggroRange; }
	sf::Vector2f GetClosePosition(float radius);
	GameObject* GetAggroObj()  { return aggroObj; }
	void SetAggroObj(GameObject* obj) { aggroObj = obj; }
	bool IsOnCooldown() const { return attackClock.getElapsedTime().asSeconds() < 3.0f; }
};