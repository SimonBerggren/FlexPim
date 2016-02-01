#pragma once
#include "GameObject.h"
#include "Assets.h"

class Hero : public GameObject
{
public:
	Hero();
	~Hero();

	virtual void Update(float delta) override;
	inline virtual const sf::Texture* const SelectedTexture() const override { return SelectedPlayerTexture(); }
};