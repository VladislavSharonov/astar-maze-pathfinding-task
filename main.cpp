#include "Maze.h"

int main()
{
	Maze maze;
	maze.ReadMaze("input.txt");
	maze.PrintPath();
	return 0;
}
