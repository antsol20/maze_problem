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

	void initialize() {

		for (int i = 0; i < this->num_of_rows; i++) {
			std::vector<Cell> row_vec;

			for (int j = 0; j < this->num_of_cols; j++) {
				row_vec.push_back(Cell(i, j));
			}

			this->cells.push_back(row_vec);
		}

		this->set_outside_walls();

		return;
	}

private:
	void set_outside_walls() {

		for (int i = 0; i < this->num_of_rows; i++) {
			for (int j = 0; j < this->num_of_cols; j++) {

				if (i == 0) {
					this->cells[i][j].walls[0] = true;
				}

				if (i == this->num_of_rows - 1) {
					this->cells[i][j].walls[2] = true;
				}

				if (j == 0) {
					this->cells[i][j].walls[1] = true;
				}

				if (j == this->num_of_cols - 1) {
					this->cells[i][j].walls[2] = true;
				}
			}
		}

		return;
	}

};

