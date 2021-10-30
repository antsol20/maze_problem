#include <iostream>
#include "maze.h"
#include <stack>
#include <vector>
#include <string>

#define PRINT_OUT(x) (std::cout << x << std::endl)

void print_maze(Maze& maze) {

	for (int i = 0; i < maze.width; i++) {

		for (int j = 0; j < maze.height; j++) {

			if (!maze.cells[i][j].walls[0] && !maze.cells[i][j].walls[1] && !maze.cells[i][j].walls[2] && !maze.cells[i][j].walls[3]) {

				std::cout << "-";
			}
			else {
				std::cout << "+";
			}
		}
		std::cout << std::endl;
	}
}

void print2_maze(Maze& maze) {

	for (int i = 0; i < maze.width; i++) {

		for (int j = 0; j < maze.height; j++) {

			auto cell = maze.cells[i][j];
			std::string msg;

			if (cell.walls[0] && cell.walls[1] && cell.walls[2] && cell.walls[3]) {

				msg = "□";
			}
			else {
				msg = "n";
			}

			std::cout << msg;

		}

		std::cout << std::endl;
	}
}


int main()
{
	PRINT_OUT("Welcome");

	int rows = 5;
	int cols = 5;

	Maze my_maze(rows, cols);
	print_maze(my_maze);


	std::stack<Cell*> my_stack;
	my_stack.push(&my_maze.cells[0][0]);
	int visited = 1;


	while (visited < rows * cols) {

		std::vector<int> neighbours;

		auto current = my_stack.top();
		current->visited = true;

		PRINT_OUT("visting (" << current->x << "," << current->y << ")");
		auto test = "test";

		// check northern neighbour
		if (current->y > 0 && my_maze.cells[current->x][current->y - 1].visited == false) {
			neighbours.push_back(0);
		}

		// check eastern neighbour
		if (current->x < my_maze.width - 1 && my_maze.cells[current->x + 1][current->y].visited == false) {
			neighbours.push_back(1);
		}

		// check southern neighbour
		if (current->y < my_maze.height - 1 && my_maze.cells[current->x][current->y + 1].visited == false) {
			neighbours.push_back(2);
		}

		// check western neighbour
		if (current->x > 0 && my_maze.cells[current->x - 1][current->y].visited == false) {
			neighbours.push_back(3);
		}

		if (!neighbours.empty()) {

			int next_cell_dir = neighbours[rand() % neighbours.size()];

			switch (next_cell_dir) {

			case 0:   // northern neighbour
				my_stack.push(&my_maze.cells[current->x][current->y - 1]);

				my_maze.cells[current->x][current->y].walls[0] = false;
				my_maze.cells[current->x][current->y - 1].walls[2] = false;

				break;

			case 1:  // eastern neighbour
				my_stack.push(&my_maze.cells[current->x + 1][current->y]);

				my_maze.cells[current->x][current->y].walls[1] = false;
				my_maze.cells[current->x + 1][current->y].walls[3] = false;


				break;

			case 2:  // southern neighbour
				my_stack.push(&my_maze.cells[current->x][current->y + 1]);

				my_maze.cells[current->x][current->y].walls[2] = false;
				my_maze.cells[current->x][current->y + 1].walls[0] = false;

				break;

			case 3:  // western neighbour
				my_stack.push(&my_maze.cells[current->x - 1][current->y]);

				my_maze.cells[current->x][current->y].walls[3] = false;
				my_maze.cells[current->x - 1][current->y].walls[1] = false;

				break;
			}

			visited++;
		}

		else {
			my_stack.pop();
		}
	}

	print2_maze(my_maze);
}
