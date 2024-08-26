#pragma once

#include "Point.h"

class AStarNode
{
public:
	explicit AStarNode() = default;

	explicit AStarNode(const Point& newPosition, const AStarNode* newPrevious = nullptr)
	    : position(newPosition), previous(newPrevious)
	{
	}

	Point position;
	const AStarNode* previous = nullptr;

	int heuristic = 0;
	int cost = 0;
	int potentialCost = 0;

	void Reset();

	static int ComputePotentialCost(int cost, int heuristic)
	{
		return cost + heuristic;
	}

	void UpdatePotentialCost()
	{
		potentialCost = ComputePotentialCost(cost, heuristic);
	}

	// Overload comparison operators for priority queue
	bool operator>(const AStarNode& other) const;
	bool operator==(const AStarNode& other) const;
};
