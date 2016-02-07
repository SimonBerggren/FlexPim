#include "HUD.h"

HUD::HUD(int& gold, int& buildings, int& units)
	: gold(gold), buildings(buildings), units(units)
{
	setTexture(*HUDTexture());
	setOrigin(sf::Vector2f(this->getTextureRect().width / 2, this->getTextureRect().height / 2));

	goldText = sf::Text("Gold: " + ToString(gold), *Font());
	goldText.setOrigin(GetOrigin(getGlobalBounds()));

	buildingsText = sf::Text("Buildings: " + ToString(buildings), *Font());
	buildingsText.setOrigin(GetOrigin(getGlobalBounds()));
	buildingsText.move(sf::Vector2f(0.0f, buildingsText.getCharacterSize() * 1.5f));

	unitsText = sf::Text("Units: " + ToString(units), *Font());
	unitsText.setOrigin(GetOrigin(getGlobalBounds()));
	unitsText.move(sf::Vector2f(0.0f, buildingsText.getCharacterSize() * 2.5f));
}

HUD::~HUD()
{

}

void HUD::Draw(sf::RenderWindow * window)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		return;

	sf::Vector2f offset(-window->getView().getSize().x / 3.0f, window->getView().getSize().y / 4.0f);
	setPosition(window->getView().getCenter() + offset);
	window->draw(*this);

	sf::Vector2f textHeight(0.0f, goldText.getCharacterSize());

	goldText.setString("Gold: " + ToString(gold));
	goldText.setPosition(getPosition());
	window->draw(goldText);

	buildingsText.setString("Buildings: " + ToString(buildings));
	buildingsText.setPosition(getPosition() + textHeight * 1.5f);
	window->draw(buildingsText);

	unitsText.setString("Units: " + ToString(units));
	unitsText.setPosition(getPosition() + textHeight * 3.0f);
	window->draw(unitsText);
}