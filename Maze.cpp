#include "Maze.h"

#include <fstream>

void Maze::ReadMaze(const char* inputFilename)
{
	std::ifstream file(inputFilename);
	if (!file.is_open())
	{
		std::cout << "File \"" << inputFilename << "\" is not found!";
		return;
	}

	int y = 0;
	int x = 0;

	char c;
	while (file.get(c))
	{
		if (c == wallChar)
			graph.Exclude(Point(x, y));

		if (c == startChar)
			start = Point(x, y);

		if (c == finishChar)
			finish = Point(x, y);

		if (c == '\n')
		{
			x = 0;
			++y;
		}
		else
			++x;
	}
	graph.SetSize(x, y + 1);
}

void Maze::PrintPath()
{
	std::unordered_set<Point> path = graph.FindPathPoints(start, finish);
	for (int y = 0; y < graph.GetHeight(); ++y)
	{
		for (int x = 0; x < graph.GetWidth(); ++x)
		{
			Point position(x, y);

			if (position == start)
				std::cout << startChar;
			else if (position == finish)
				std::cout << finishChar;
			else if (path.find(position) != path.end())
				std::cout << pathChar;
			else
				std::cout << (graph.Contains(position) ? spaceChar : wallChar);
		}
		std::cout << "\n";
	}
}
