#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include "maze.h"
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

	void draw_maze() {

		std::stack<Cell*> my_stack;
		my_stack.push(&this->cells[0][0]);
		int visited = 1;


		while (visited < width * height) {

			std::vector<int> neighbours;

			auto current = my_stack.top();
			current->visited = true;

			std::cout << "visting (" << current->x << "," << current->y << ")" << std::endl;

			// check northern neighbour
			if (current->y > 0 && this->cells[current->x][current->y - 1].visited == false) {
				neighbours.push_back(0);
			}

			// check eastern neighbour
			if (current->x < this->width - 1 && this->cells[current->x + 1][current->y].visited == false) {
				neighbours.push_back(1);
			}

			// check southern neighbour
			if (current->y < this->height - 1 && this->cells[current->x][current->y + 1].visited == false) {
				neighbours.push_back(2);
			}

			// check western neighbour
			if (current->x > 0 && this->cells[current->x - 1][current->y].visited == false) {
				neighbours.push_back(3);
			}

			if (!neighbours.empty()) {

				int next_cell_dir = neighbours[rand() % neighbours.size()];

				switch (next_cell_dir) {

				case 0:   // northern neighbour
					my_stack.push(&this->cells[current->x][current->y - 1]);

					this->cells[current->x][current->y].walls[0] = false;
					this->cells[current->x][current->y - 1].walls[2] = false;

					break;

				case 1:  // eastern neighbour
					my_stack.push(&this->cells[current->x + 1][current->y]);

					this->cells[current->x][current->y].walls[1] = false;
					this->cells[current->x + 1][current->y].walls[3] = false;


					break;

				case 2:  // southern neighbour
					my_stack.push(&this->cells[current->x][current->y + 1]);

					this->cells[current->x][current->y].walls[2] = false;
					this->cells[current->x][current->y + 1].walls[0] = false;

					break;

				case 3:  // western neighbour
					my_stack.push(&this->cells[current->x - 1][current->y]);

					this->cells[current->x][current->y].walls[3] = false;
					this->cells[current->x - 1][current->y].walls[1] = false;

					break;
				}

				visited++;
			}

			else {
				my_stack.pop();
			}
		}


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
