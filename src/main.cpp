#include <iostream>
#include "maze.h"

int main()
{
	std::cout << "hello";

	int rows = 5;
	int cols = 6;

	Maze maze(rows, cols);
	maze.cells;

	Cell cell1;
	cell1.walls[0] = true;
	cell1.walls[1] = true;
	cell1.walls[2] = true;
	cell1.walls[3] = true;

	Cell cell2;
	cell2.walls[0] = false;
	cell2.walls[1] = false;
	cell2.walls[2] = false;
	cell2.walls[3] = false;

	//maze.cells.push_back(cell1, cell2);





}