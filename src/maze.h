#pragma once
#include <vector>
#include "cell.h"

class Maze
{

public:
	int num_of_rows;
	int num_of_cols;
	std::vector<std::vector<Cell>> cells;

	Maze(int rows, int cols)
	{
		num_of_rows = rows;
		num_of_cols = cols;
	}

};

