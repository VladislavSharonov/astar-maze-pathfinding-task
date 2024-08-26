#pragma once

#include "AStarGraph.h"
#include "AStarNode.h"

class Maze
{
public:
	void ReadMaze(const char* inputFilename);
	
	void PrintPath();

private:
	Point start;
	Point finish;
	AStarGraph graph;

	static constexpr char startChar = 'S';
	static constexpr char finishChar = 'F';
	static constexpr char wallChar = 'x';
	static constexpr char spaceChar = '.';
	static constexpr char pathChar = '*';
};
