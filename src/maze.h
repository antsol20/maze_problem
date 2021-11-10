#pragma once
#include <vector>
#include "cell.h"

class Maze
{

public:

	int width;
	int height;
	std::vector<std::vector<Cell>> cells;

	Maze(int rows, int cols);

	void draw_maze();

	void print_maze();

private:
	void initialise();

};
