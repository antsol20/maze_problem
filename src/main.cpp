#include <iostream>
#include "maze.h"
#include <stack>

#define PRINT_OUT(x) (std::cout << x << std::endl)

int main()
{
	PRINT_OUT("hello");

	int rows = 5;
	int cols = 6;

	Maze maze(rows, cols);
	maze.cells;

	Cell cell1;
	cell1.x = 1;
	cell1.y = 2;
	cell1.walls = { true, true, true, true };

	Cell cell2;
	cell2.x = 3;
	cell2.y = 0;
	cell1.walls = { true, false, true, true };

	std::vector<Cell> cell_vec = { cell1, cell2 };

	maze.cells.push_back(cell_vec);

	PRINT_OUT(maze.cells[0][0].x);
	PRINT_OUT(maze.cells[0][0].y);
}

void createMaze() {

	Maze maze(4, 4);
	in

	std::stack<Cell> visit_stack;
	visit_stack.push(Cell(0, 0));



}