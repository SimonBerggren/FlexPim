#pragma once
#include "SFML/Graphics.hpp"

enum TileType
{
	Walkable,
	NonWalkable,
};

template<TileType T = TileType::Walkable>
struct Tile : public sf::RectangleShape
{
	Tile() : type(T) { }
	Tile(const sf::Vector2f& position) : m_position(position), type(T) { }
	void SetType(TileType type) { this->type = type; }
	TileType type;
};