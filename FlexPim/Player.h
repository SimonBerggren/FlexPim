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

	sf::RenderWindow* window;
	GameObject* selected;
	Fortress* fort;
	Hero* hero;
	HUD* hud;

public:
	Player(sf::RenderWindow* window);
	virtual ~Player();

	void Update(float delta);
	void Draw(sf::RenderWindow* window);

	Fortress* GetFort() const { return fort; }
	Hero* GetHero() const { return hero; }
	HUD* GetHUD() const { return hud; }
};