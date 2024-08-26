#pragma once

#include <unordered_set>
#include <cmath>
#include <vector>
#include <unordered_map>

#include "Point.h"
#include "AStarNode.h"

class AStarGraph
{
public:
	void SetSize(uint32_t width, uint32_t height);

	void Exclude(const Point& point);

	// Is point valid for the grid?
	bool Contains(const Point& point) const;

	uint32_t GetWidth() const
	{
		return _width;
	}

	uint32_t GetHeight() const
	{
		return _height;
	}

	// Find unordered points of the path.
	std::unordered_set<Point> FindPathPoints(const Point& start, const Point& finish);

private:
	std::unordered_set<Point> excluded;

	// Safe version of std::unordered_map<Point, AStarNode*>.
	struct GuardedGraph : std::unordered_map<Point, AStarNode*>
	{
		~GuardedGraph()
		{
			Reset();
		}

		void Reset()
		{
			for (auto& i : *this)
				delete i.second;
			clear();
		}

		// Get node by its point.
		AStarNode* Get(const Point& position)
		{
			auto node = find(position);
			return node == end() ? nullptr : at(position);
		}

		// Get or create node by its point.
		AStarNode* GetOrAdd(const Point& position)
		{
			if (find(position) == end())
				insert({position, new AStarNode(position)});
			return at(position);
		}
	} graph;

	uint32_t _width = 0;
	uint32_t _height = 0;

	// Is point in bounds of grid?
	bool IsInBounds(const Point& point) const;

	// Get Neighbors without diagonals.
	std::vector<Point> GetOrthogonalNeighbors(const Point& point) const;

	void DetectPath(const Point& start, const Point& finish);

	static int ComputeManhattanDistance(const Point& point1, const Point& point2);

	struct StarNodePtrGreater
	{
		bool operator()(const AStarNode* start, const AStarNode* finish)
		{
			return *start > *finish;
		}
	};
};
