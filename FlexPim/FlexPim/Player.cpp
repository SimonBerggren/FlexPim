#include "Player.h"
#include <iostream>

Player::Player()
{
	gold = 500;
	fort = new Fortress(sf::Vector2f(0, 0));
	hero = new Hero();
	hud = new HUD(gold, buildings, units);
	selected = nullptr;
}

Player::~Player()
{
	delete fort;
	delete hero;
	delete hud;
}

void Player::Update(float delta)
{
	hero->Update(delta);
	fort->Update(delta);
}

void Player::Draw(sf::RenderWindow * window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (hero->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
		{
			hero->Select(true);
			selected = hero;
		}
		else
		{
			hero->Select(false);
			selected = nullptr;
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (selected)
			selected->MoveTo(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
	}

	hud->Draw(window);
	fort->Draw(window);
	hero->Draw(window);
}