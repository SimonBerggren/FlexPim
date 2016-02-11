#pragma once
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/Keyboard.hpp"

class PlayerController
{
	bool enabled;
public:
	PlayerController();
	~PlayerController();

	bool LeftClicked() const { return enabled && sf::Mouse::isButtonPressed(sf::Mouse::Left); }
	bool RightClicked() const { return enabled && sf::Mouse::isButtonPressed(sf::Mouse::Right); }
	bool ClickedKey(const sf::Keyboard::Key& key) const { return enabled && sf::Keyboard::isKeyPressed(key); }

	bool IsEnabled() const { return enabled; }
	void Enable() { enabled = true; }
	void Disable() { enabled = false; }
};