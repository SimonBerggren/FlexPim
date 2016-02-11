#include "Assets.h"

const sf::Texture * const PlayerTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/Player.png");
	return texture;
}

const sf::Texture * const SelectedPlayerTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/PlayerSelected.png");
	return texture;
}

const sf::Texture * const WorldTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/World.png");
	return texture;
}

const sf::Texture * const HeadQuartersTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/HeadQuarters.png");
	return texture;
}

const sf::Texture* const HUDTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/HUD.png");
	return texture;
}

const sf::Texture* const BuildingHUDTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/BuildingHUD.png");
	return texture;
}

const sf::Texture * const GoatTexture()
{
	static sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("../Assets/Images/Goat.png");
	return texture;
}

const sf::Font* const Font()
{
	static sf::Font* font = new sf::Font();
	font->loadFromFile("../Assets/Fonts/Font.otf");
	return font;
}