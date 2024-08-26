#include <queue>
#include "AStarGraph.h"

void AStarGraph::SetSize(uint32_t width, uint32_t height)
{
	_width = width;
	_height = height;
}

void AStarGraph::Exclude(const Point& point)
{
	excluded.insert(point);
}

bool AStarGraph::Contains(const Point& point) const
{
	return IsInBounds(point) && excluded.find(point) == excluded.end();
}

bool AStarGraph::IsInBounds(const Point& point) const
{
	return point.x >= 0 && point.x < _width && point.y >= 0 && point.y < _height;
}

std::vector<Point> AStarGraph::GetOrthogonalNeighbors(const Point& point) const
{
	std::vector<Point> neighbors;
	for (int x = -1; x <= 1; ++x)
	{
		for (int y = -1; y <= 1; ++y)
		{
			// Except diagonals and center.
			if (std::abs(x) == std::abs(y))
				continue;

			Point neighbor(point.x + x, point.y + y);
			if (Contains(neighbor))
				neighbors.push_back(neighbor);
		}
	}

	return neighbors;
}

void AStarGraph::DetectPath(const Point& start, const Point& finish)
{
	std::priority_queue<AStarNode*, std::vector<AStarNode*>, StarNodePtrGreater> openList;
	std::unordered_set<AStarNode*> closed;

	AStarNode* startNode = graph.GetOrAdd(start);
	startNode->position = start;
	openList.emplace(startNode);

	while (!openList.empty())
	{
		// Get the cell with the lowest potentialCost value from the open list
		AStarNode* current = openList.top();
		openList.pop();
		closed.insert(current);

		// Check if the current cell is the finish
		if (current == graph.GetOrAdd(finish))
			return;  // Path found.

		// Explore neighbors
		std::vector<Point> neighborPositions = GetOrthogonalNeighbors(current->position);
		for (const Point& neighborPosition : neighborPositions)
		{
			AStarNode* neighbor = graph.GetOrAdd(neighborPosition);

			if (closed.find(neighbor) != closed.end())
				continue;

			int newCost = current->cost + 1;
			if (newCost < neighbor->cost || neighbor->cost == 0)  // neighbor.cost == 0 means this cell is just opened.
			{
				// Set current as previous in path.
				neighbor->position = neighborPosition;
				neighbor->cost = newCost;
				neighbor->heuristic = ComputeManhattanDistance(current->position, finish);
				neighbor->previous = current;
				neighbor->UpdatePotentialCost();
				openList.push(neighbor);
			}
		}
	}
}

std::unordered_set<Point> AStarGraph::FindPathPoints(const Point& start, const Point& finish)
{
	DetectPath(start, finish);
	std::unordered_set<Point> path;
	const AStarNode* current = graph.Get(finish);

	while (current != nullptr)
	{
		path.insert(current->position);
		current = current->previous;

		if (current != nullptr && current->position == start)
			break;
	}

	graph.Reset();
	return path;
}

int AStarGraph::ComputeManhattanDistance(const Point& point1, const Point& point2)
{
	return std::abs(point1.x - point2.x) + std::abs(point1.y - point2.y);
}
