#include <iostream>
#include "maze.h"
#include <stack>

#define PRINT_OUT(x) (std::cout << x << std::endl)
#define GEN_RAND (rand() % 2)


void initialize_maze(Maze& maze) {

	for (int i = 0; i < maze.num_of_rows; i++) {
		std::vector<Cell> row_vec;

		for (int j = 0; j < maze.num_of_cols; j++) {
			row_vec.push_back(Cell(i, j));
		}

		maze.cells.push_back(row_vec);
	}

	return;
}

void set_outside_walls(Maze& maze) {

	for (int i = 0; i < maze.num_of_rows; i++) {
		for (int j = 0; j < maze.num_of_cols; j++) {

			if (i == 0) {
				maze.cells[i][j].walls[0] = true;
			}

			if (i == maze.num_of_rows - 1) {
				maze.cells[i][j].walls[2] = true;
			}

			if (j == 0) {
				maze.cells[i][j].walls[1] = true;
			}

			if (j == maze.num_of_cols - 1) {
				maze.cells[i][j].walls[2] = true;
			}
		}
	}

	return;
}

void print_maze(Maze& maze) {

	for (int i = 0; i < maze.num_of_rows; i++) {

		for (int j = 0; j < maze.num_of_cols; j++) {
			
			if (maze.cells[i][j].walls[0] == false && maze.cells[i][j].walls[1] == false && maze.cells[i][j].walls[2] == false && maze.cells[i][j].walls[2] == false) {
				std::cout << ".";
			}
			else {
				std::cout << "+";
			}
		}
		std::cout << std::endl;
	}
}


int main()
{
	PRINT_OUT("Welcome");

	Maze my_maze(6, 5);
	initialize_maze(my_maze);
	set_outside_walls(my_maze);
	print_maze(my_maze);

	PRINT_OUT("finished");

}
