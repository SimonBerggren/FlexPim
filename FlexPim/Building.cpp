#include "Building.h"

Building::Building(const sf::Texture& texture, const sf::Vector2f& position)
	: GameObject(texture, position)
{
	hud = nullptr;
}

Building::~Building()
{

}

void Building::Select(bool selected)
{
	GameObject::Select(selected);

	if (isSelected && !hud)
		hud = new	BuildingHUD();
	else if (!selected && hud)
	{
		delete hud;
		hud = nullptr;
	}
}

void Building::Draw(sf::RenderWindow * window)
{
	GameObject::Draw(window);

	if (hud)
		hud->Draw(window);
}