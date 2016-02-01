#include "GameObject.h"

GameObject::GameObject(const sf::Texture& texture)
{
	setTexture(texture, true);
	this->texture = getTexture();
	setOrigin(sf::Vector2f(this->getTextureRect().width / 2, this->getTextureRect().height / 2));
	isDead = false;
	hasGoal = false;
	isSelected = false;
}

GameObject::~GameObject()
{

}

void GameObject::Update(float delta)
{
	if (hasGoal)
	{
		if (VectorDistance(getPosition(), goal) > 2)
			move(DirectionBetween(getPosition(), goal) * delta);
		else
			hasGoal = false;
	}
}

void GameObject::Draw(sf::RenderWindow * window)
{
	window->draw(*this);
}

void GameObject::DoDamage(float damage)
{

}

void GameObject::Select(bool selected)
{
	isSelected = selected;
	if (isSelected && SelectedTexture())
		setTexture(*SelectedTexture());
	else if (!isSelected)
		setTexture(*texture);
}

void GameObject::MoveTo(const sf::Vector2f & newGoal)
{
	goal = newGoal;
	hasGoal = true;
}