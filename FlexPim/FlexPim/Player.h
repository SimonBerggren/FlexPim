#pragma once
#include "Fortress.h"
#include "Hero.h"
#include "HUD.h"

class Player
{
	int gold;
	int buildings;
	int units;

	Fortress* fort;
	Hero* hero;
	HUD* hud;

	GameObject* selected;
public:
	Player();
	~Player();

	void Update(float delta);
	void Draw(sf::RenderWindow* window);
};