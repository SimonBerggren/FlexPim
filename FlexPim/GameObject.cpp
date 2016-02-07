#include "GameObject.h"
#include "SFML/Graphics.hpp" // for rectangle shape in draw (if selected) - early stage

GameObject::GameObject(const sf::Texture& texture, const sf::Vector2f& position)
{
	setPosition(position);
	setTexture(texture, true);
	setOrigin(sf::Vector2f(this->getTextureRect().width / 2, this->getTextureRect().height / 2));
	isDead = false;
	isSelected = false;
}

GameObject::~GameObject()
{

}

void GameObject::Update(float delta)
{

}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(*this);

	if (isSelected)
	{
		sf::RectangleShape shape(sf::Vector2f(getGlobalBounds().width, getGlobalBounds().height));
		shape.setOrigin(shape.getSize() / 2.0f);
		shape.setPosition(getPosition());
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineColor(sf::Color::Green);
		shape.setOutlineThickness(2.0f);
		window->draw(shape);
	}
}

void GameObject::DoDamage(float damage)
{
	if (damage <= 0.0f)
		return;

	health = Clamp(health - damage, 0.0f, health);

	if (health == 0.0f)
		isDead = true;
}

void GameObject::Select(bool selected)
{
	isSelected = selected;
}