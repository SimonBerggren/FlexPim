#pragma once
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/Keyboard.hpp"

class PlayerController
{
	bool enabled;
public:
	PlayerController();
	~PlayerController();

	
	inline const bool LeftClicked() const { return enabled && sf::Mouse::isButtonPressed(sf::Mouse::Left); }
	inline const bool RightClicked() const { return enabled && sf::Mouse::isButtonPressed(sf::Mouse::Right); }
	inline const bool ClickedKey(const sf::Keyboard::Key& key) const { return enabled && sf::Keyboard::isKeyPressed(key); }
	inline const bool IsEnabled() const { return enabled; }
	inline void Enable() { enabled = true; }
	inline void Disable() { enabled = false; }
};