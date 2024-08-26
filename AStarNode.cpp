#include "AStarNode.h"

void AStarNode::Reset()
{
	heuristic = 0;
	cost = 0;
	potentialCost = 0;
	previous = nullptr;
}

bool AStarNode::operator>(const AStarNode& other) const
{
	return potentialCost > other.potentialCost;
}

bool AStarNode::operator==(const AStarNode& other) const
{
	return position == other.position;
}
