#include "WorldObjects.h"

std::vector<GameObject*> WorldObjects::objects;

void WorldObjects::AddObject(GameObject * object)
{
	objects.push_back(object);
}

void WorldObjects::RemoveObject(GameObject * object)
{
	std::vector<GameObject*>::iterator objToRemove = std::find(objects.begin(), objects.end(), object);

	if (objToRemove != objects.end())
		objects.erase(objToRemove);
}

void WorldObjects::RemoveObjectAt(int position)
{
	std::vector<GameObject*>::iterator objToRemove = std::find(objects.begin(), objects.end(), objects[position]);

	if (objToRemove != objects.end())
		objects.erase(objToRemove);
}

GameObject* WorldObjects::FindObject(GameObject * object)
{
	std::vector<GameObject*>::iterator returnObj = std::find(objects.begin(), objects.end(), object);

	if (returnObj != objects.end())
		return *returnObj;
	else
		return nullptr;
}

GameObject* WorldObjects::FindObject(const sf::Vector2f & position)
{
	for (int i = 0; i < Count(); ++i)
		if (objects[i]->getGlobalBounds().contains(position))
			return objects[i];

	return nullptr;
}

GameObject * WorldObjects::FindObject(const sf::Vector2f & position, float range)
{
	for (int i = 0; i < Count(); ++i)
	{
		if (objects[i]->getPosition().x >(position.x - range) &&
			objects[i]->getPosition().x < (position.x + range) &&
			objects[i]->getPosition().y >(position.y - range) &&
			objects[i]->getPosition().y < (position.y + range))
		{
			return objects[i];
		}
	}

	return nullptr;
}

GameObject* WorldObjects::FindObject(int position)
{
	if (position >= 0 && position < Count())
		return objects[position];
	else
		return nullptr;
}

bool WorldObjects::Intersects(const sf::Shape& shape)
{
	for (int i = 0; i < Count(); ++i)
	{
		if (shape.getGlobalBounds().intersects(objects[i]->getGlobalBounds()))
			return true;
	}
	return false;
}

bool WorldObjects::Intersects(const sf::FloatRect & bounds)
{
	for (int i = 0; i < Count(); ++i)
	{
		if (bounds.intersects(objects[i]->getGlobalBounds()))
			return true;
	}
	return false;
}
