#include "BuildingHUD.h"

BuildingHUD::BuildingHUD()
	: sf::Sprite(*BuildingHUDTexture())
{

}

BuildingHUD::~BuildingHUD()
{
}

void BuildingHUD::Draw(sf::RenderWindow * window)
{
	sf::Vector2f offset(window->getView().getSize().x / 2.0f, window->getView().getSize().y / 2.0f + getGlobalBounds().height);
	setPosition(window->getView().getCenter());
	window->draw(*this);
}