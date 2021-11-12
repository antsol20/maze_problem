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

	void reset_visited();

	bool path_find(int start_x, int start_y, int end_x, int end_y);

private:
	void initialise();

};
