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
	}

	void initialize() {

		for (int i = 0; i < this->width; i++) {
			std::vector<Cell> row_vec;

			for (int j = 0; j < this->height; j++) {
				row_vec.push_back(Cell(i, j));
			}

			this->cells.push_back(row_vec);
		}

		this->set_outside_walls();

		return;
	}

private:
	void set_outside_walls() {

		for (int i = 0; i < this->width; i++) {

			for (int j = 0; j < this->height; j++) {

				if (i == 0) {
					this->cells[i][j].walls[0] = true;
				}

				if (i == this->width - 1) {
					this->cells[i][j].walls[1] = true;
				}

				if (j == 0) {
					this->cells[i][j].walls[3] = true;
				}

				if (j == this->height - 1) {
					this->cells[i][j].walls[2] = true;
				}
			}
		}

		return;
	}

};

