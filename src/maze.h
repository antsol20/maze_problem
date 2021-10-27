#pragma once
#include <vector>
#include "cell.h"

class Maze
{
public:
	int rows;
	int cols;
	std::vector<Cell, Cell> cells;

	Maze(int num_of_rows, int num_of_cols)
	{
		rows = num_of_rows;
		cols = num_of_cols;
	}

	

};

