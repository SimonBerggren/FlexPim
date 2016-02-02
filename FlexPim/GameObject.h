#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Utils.h"

class GameObject : public sf::Sprite
{
protected:
	float health;
	bool isDead;
	bool isSelected;
	bool hasGoal;

	sf::Vector2f goal;

	const sf::Texture *texture;

public:
	GameObject(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~GameObject();

	virtual void Update(float delta);
	virtual void Draw(sf::RenderWindow* window);
	virtual void DoDamage(float damage);

	void Select(bool selected);
	void MoveTo(const sf::Vector2f& newGoal);
	inline virtual const  sf::Texture* const SelectedTexture() const { return nullptr; }
};