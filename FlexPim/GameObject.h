#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Utilities.h"

class GameObject : public sf::Sprite
{
protected:
	float health;
	bool isDead;
	bool isSelected;

	sf::Vector2f goal;

public:
	GameObject(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~GameObject();

	virtual void Update(float delta);
	virtual void Draw(sf::RenderWindow* window);
	virtual void DoDamage(float damage);

	virtual void Select(bool selected);
	inline virtual const  sf::Texture* const SelectedTexture() const { return nullptr; }
};