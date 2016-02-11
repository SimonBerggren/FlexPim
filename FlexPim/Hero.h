#pragma once
#include "MovableObject.h"
#include "Assets.h"

class Hero : public MovableObject
{
public:
	Hero(const sf::Vector2f& position);
	~Hero();

	virtual void Update(float delta) override;
	//inline virtual const sf::Texture* const SelectedTexture() const override { return SelectedPlayerTexture(); }
};