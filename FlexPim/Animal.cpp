#include "Animal.h"

Animal::Animal(const sf::Texture& texture, const sf::Vector2f& position)
	: MovableObject(texture, position)
{
	fsm->ChangeGlobalState(StrollingAround::Instance());
}

Animal::~Animal()
{

}