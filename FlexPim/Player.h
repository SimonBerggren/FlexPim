#pragma once
#include "WorldObjects.h"
#include "Fortress.h"
#include "Hero.h"
#include "HUD.h"

class Player
{
	friend class World;

	int gold;
	int buildings;
	int units;

	GameObject* selected;
	Fortress* fort;
	Hero* hero;
	HUD* hud;

public:
	Player();
	~Player();

	void Update(float delta);
	void Draw(sf::RenderWindow* window);

	const Fortress& GetFort() const { return *fort; }
	const Hero& GetHero() const { return *hero; }
	const HUD& GetHUD() const { return *hud; }
};