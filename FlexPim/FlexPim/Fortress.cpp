#include "Fortress.h"

Fortress::Fortress(const sf::Vector2f& position)
	:Building(position, *HeadQuartersTexture())
{

}

Fortress::~Fortress()
{

}