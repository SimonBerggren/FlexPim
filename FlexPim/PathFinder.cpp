#include "PathFinder.h"

PathFinder::PathFinder()
{
	initializedStartGoal = false;
	foundGoal = false;
}

PathFinder::~PathFinder()
{
}

void PathFinder::FindPath(const sf::Vector2f & currPos, const sf::Vector2f & targetPos)
{
	if (!initializedStartGoal)
	{
		for (int i = 0; i < openList.size(); ++i)
		{
			delete openList[i];
		}
		openList.clear();

		for (int i = 0; i < visitedList.size(); ++i)
		{
			delete visitedList[i];
		}
		visitedList.clear();

		for (int i = 0; i < pathToGoal.size(); ++i)
		{
			delete pathToGoal[i];
		}
		pathToGoal.clear();

		SearchCell start;
		start.x = currPos.x;
		start.y = currPos.y;

		SearchCell goal;
		goal.x = targetPos.x;
		goal.y = targetPos.y;

		SetStartAndGoal(start, goal);
		initializedStartGoal = true;
	}
	if (initializedStartGoal)
		ContinuePath();
}

sf::Vector2f PathFinder::NextPathPos(MovableObject* obj)
{
	int index = 1;

	sf::Vector2f nextPos;
	nextPos.x = pathToGoal[pathToGoal.size() - index]->x;
	nextPos.y = pathToGoal[pathToGoal.size() - index]->y;

	sf::Vector2f distance = nextPos - obj->getPosition();

	if (index < pathToGoal.size())
	{
		if (VectorLength(distance) < obj->getGlobalBounds().width * 0.25f)
		{
			pathToGoal.erase(pathToGoal.end() - index);
		}
	}

	return nextPos;
}

void PathFinder::SetStartAndGoal(SearchCell start, SearchCell goal)
{
	startCell = new SearchCell(start.x, start.y, NULL);
	goalCell = new SearchCell(goal.x, goal.y, &goal);

	startCell->G = 0;
	startCell->H = startCell->ManHattanDistance(goalCell);

	openList.push_back(startCell);
}

void PathFinder::PathOpened(int x, int y, float newCost, SearchCell * parent)
{
	int id = y * WORLD_SIZE + x;

	for (int i = 0; i < visitedList.size(); ++i)
	{
		if (id == visitedList[i]->id)
			return;
	}

	SearchCell* newChild = new SearchCell(x, y, parent);
	newChild->G = newCost;
	newChild->H = parent->ManHattanDistance(goalCell);

	for (int i = 0; i < openList.size(); ++i)
	{
		if (openList[i]->id == id)
		{
			float newF = newChild->G + newCost + openList[i]->H;

			if (openList[i]->GetF() > newF)
			{
				openList[i]->G = newChild->G + newCost;
				openList[i]->parent = newChild;
			}
			else
			{
				delete newChild;
				return;
			}
		}
	}

	openList.push_back(newChild);
}

SearchCell * PathFinder::GetNextCell()
{
	float bestF = std::numeric_limits<float>::max();
	int cellIndex = -1;
	SearchCell* nextCell = nullptr;

	for (int i = 0; i < openList.size(); ++i)
	{
		if (openList[i]->GetF() < bestF)
			cellIndex = i;
	}

	if (cellIndex >= 0)
	{
		nextCell = openList[cellIndex];
		visitedList.push_back(nextCell);
		openList.erase(openList.begin() + cellIndex);
	}

	return nextCell;
}

void PathFinder::ContinuePath()
{
	if (openList.empty())
	{
		return;
	}

	SearchCell* currentCell = GetNextCell();
	if (currentCell->id == goalCell->id)
	{
		goalCell->parent = currentCell->parent;

		SearchCell* getPath; 

		for (getPath = goalCell; getPath != NULL; getPath = getPath->parent)
		{
			pathToGoal.push_back(new sf::Vector2f(getPath->x, getPath->y));
		}

		foundGoal = true;
		return;
	}
	else
	{
		// right cell
		PathOpened(currentCell->x + 1, currentCell->y, currentCell->G + 1, currentCell);
		// left cell 
		PathOpened(currentCell->x - 1, currentCell->y, currentCell->G + 1, currentCell);
		// up
		PathOpened(currentCell->x, currentCell->y + 1, currentCell->G + 1, currentCell);
		// down
		PathOpened(currentCell->x, currentCell->y - 1, currentCell->G + 1, currentCell);
		// left up
		PathOpened(currentCell->x + 1, currentCell->y + 1, currentCell->G + 1, currentCell);
		// left down
		PathOpened(currentCell->x + 1, currentCell->y - 1, currentCell->G + 1, currentCell);
		// right up
		PathOpened(currentCell->x - 1, currentCell->y + 1, currentCell->G + 1, currentCell);
		// right down
		PathOpened(currentCell->x - 1, currentCell->y - 1, currentCell->G + 1, currentCell);

		for (int i = 0; i < openList.size(); ++i)
		{
			if (currentCell->id == openList[i]->id)
			{
				openList.erase(openList.begin() + i);
			}
		}
	}
}