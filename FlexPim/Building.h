#pragma once
#include "GameObject.h"
#include "BuildingHUD.h"

class Building : public GameObject
{
	BuildingHUD* hud;
	Building();
public:
	Building(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~Building();
	virtual void Select(bool selected) override;
	virtual void Draw(sf::RenderWindow* window) override;
};