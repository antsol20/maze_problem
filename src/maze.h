#pragma once
#include <vector>
#include "cell.h"

class Maze
{

public:

	int width;
	int height;
	std::vector<std::vector<Cell>> cells;

	Maze(int rows, int cols)
	{
		width = cols;
		height = rows;
		this->initialise();
	}

private:
	void initialise() {
		for (int i = 0; i < this->width; i++) {
			std::vector<Cell> row_vec;

			for (int j = 0; j < this->height; j++) {
				row_vec.push_back(Cell(i, j));
			}
			this->cells.push_back(row_vec);
		}
		return;
	}
};

