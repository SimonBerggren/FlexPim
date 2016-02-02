#pragma once
#include "GameObject.h"
#include "Assets.h"

class Hero : public GameObject
{
public:
	Hero(const sf::Vector2f& position);
	~Hero();

	virtual void Update(float delta) override;
	inline virtual const sf::Texture* const SelectedTexture() const override { return SelectedPlayerTexture(); }
};