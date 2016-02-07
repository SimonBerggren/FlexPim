#include "Player.h"
#include <iostream>

Player::Player(sf::RenderWindow* window)
	: window(window)
{
	gold = 500;
	fort = new Fortress(sf::Vector2f(320, 350));
	hero = new Hero(sf::Vector2f(fort->getPosition() + sf::Vector2f(fort->getGlobalBounds().width * 0.75f, fort->getGlobalBounds().height * 1.5f)));
	hud = new HUD(gold, buildings, units);
	selected = nullptr;

	WorldObjects::AddObject(fort);
	WorldObjects::AddObject(hero);
}

Player::~Player()
{
	delete fort;
	delete hero;
	delete hud;
}

void Player::Update(float delta)
{

}

void Player::Draw(sf::RenderWindow * window)
{
	hud->Draw(window);
}