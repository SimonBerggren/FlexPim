#include "Fortress.h"

Fortress::Fortress(const sf::Vector2f& position)
	:Building(*HeadQuartersTexture(), position)
{

}

Fortress::~Fortress()
{

}