#pragma once
#include "GameObject.h"

class MovableObject : public GameObject
{
	bool hasGoal;
	bool isMoving;
public:
	MovableObject(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~MovableObject();
	virtual void Update(float delta) override;
	void SetNewGoal(const sf::Vector2f& newGoal);
	void SetIsMoving(bool isMoving);
};