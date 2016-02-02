#pragma once
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
	static GameObject* FindObject(int position);

	inline static const int Count() { return objects.size(); }
};