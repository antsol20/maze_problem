#include <iostream>
#include "maze.h"
#include <stack>
#include <vector>
#include <string>

#define PRINT_OUT(x) (std::cout << x << std::endl)

void print_maze(Maze& maze) {

	for (int i = 0; i < maze.num_of_rows; i++) {

		for (int j = 0; j < maze.num_of_cols; j++) {

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


int main()
{
	PRINT_OUT("Welcome");

	int rows = 6;
	int cols = 10;

	Maze my_maze(rows, cols);
	my_maze.initialize();
	print_maze(my_maze);


	std::stack<Cell*> my_stack;
	my_stack.push(&my_maze.cells[0][0]);
	int visited = 1;


	while (visited < rows * cols) {

		std::vector<int> neighbours;

		auto top = my_stack.top();
		top->visited = true;

		PRINT_OUT("visting (" << top->x  << ","  << top->y << ")");
	
		// check northern neighbour
		if (top->y > 0 && my_maze.cells[top->x][top->y - 1].visited == false) {
			neighbours.push_back(0);
		}

		// check eastern neighbour
		if (top->x < my_maze.num_of_cols - 1 && my_maze.cells[top->x + 1][top->y].visited == false) {
			neighbours.push_back(1);
		}

		// check southern neighbour
		if (top->y < my_maze.num_of_rows - 1 && my_maze.cells[top->x][top->y + 1].visited == false) {
			neighbours.push_back(2);
		}

		// check western neighbour
		if (top->x > 0 && my_maze.cells[top->x - 1][top->y].visited == false) {
			neighbours.push_back(3);
		}

		if (!neighbours.empty()) {

			int next_cell_dir = neighbours[rand() % neighbours.size()];

			switch (next_cell_dir) {
			case 0:
				my_stack.push(&my_maze.cells[top->x][top->y - 1]);
				break;
			case 1:
				my_stack.push(&my_maze.cells[top->x + 1][top->y]);
				break;

			case 2:
				my_stack.push(&my_maze.cells[top->x][top->y + 1]);
				break;

			case 3:
				my_stack.push(&my_maze.cells[top->x - 1][top->y]);
				break;
			}

			visited++;
		}

		else {
			my_stack.pop();
		}
	}

}
