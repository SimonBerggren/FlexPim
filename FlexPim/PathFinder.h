#pragma once
#include <math.h>
#include "SFML/Graphics.hpp"
#include "MovableObject.h"
#include "Utilities.h"

#define WORLD_SIZE 64

struct SearchCell
{
	int x, y;
	int id;
	SearchCell* parent;
	float G;
	float H;

	SearchCell() : parent(nullptr) { }
	SearchCell(int x, int y, SearchCell* parent) : x(x), y(y), id(y * WORLD_SIZE + x), parent(parent), G(0), H(0) {}

	float GetF() const { return G + H; }
	float ManHattanDistance(SearchCell* node)
	{
		float x = (float)fabs(this->x - node->x);
		float y = (float)fabs(this->y - node->y);

		return x + y;
	}
};

class PathFinder
{
public:
	PathFinder();
	~PathFinder();

	void FindPath(const sf::Vector2f& currPos, const sf::Vector2f& targetPos);
	sf::Vector2f NextPathPos(MovableObject* obj);

	bool initializedStartGoal;
	bool foundGoal;

private:
	void SetStartAndGoal(SearchCell start, SearchCell goal);
	void PathOpened(int x, int y, float newCost, SearchCell* parent);
	SearchCell* GetNextCell();
	void ContinuePath();

	SearchCell* startCell;
	SearchCell* goalCell;
	std::vector<SearchCell*> openList;
	std::vector<SearchCell*> visitedList;
	std::vector<sf::Vector2f*> pathToGoal;
};