#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"

static class WorldObjects
{
	friend class World;
	static std::vector<GameObject*> objects;

public:
	static void AddObject(GameObject* object);
	static void RemoveObject(GameObject* object);
	static void RemoveObjectAt(int position);
	static GameObject* FindObject (GameObject* object);
	static GameObject* FindObject (const sf::Vector2f& position);
	static GameObject* FindObject(const sf::Vector2f& position, float range);
	static GameObject* FindObject(int position);

	static bool Intersects(const sf::Shape&);
	static bool Intersects(const sf::FloatRect&);
	inline static const size_t Count() { return objects.size(); }
};