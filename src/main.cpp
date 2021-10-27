#include <iostream>
#include "maze.h"
#include <stack>

#define PRINT_OUT(x) (std::cout << x << std::endl)
#define GEN_RAND (rand() % 2)


int main()
{
	PRINT_OUT("Welcome");

	for (size_t i = 0; i < 1000; i++)
	{
		PRINT_OUT(GEN_RAND);
	}
	
}



void createMaze() {

	int rows = 4;
	int cols = 4;

	Maze maze(rows, cols);
	int visited = 0;

	std::stack<Cell> visit_stack;
	visit_stack.push(Cell(0, 0));

	maze.cells[0][0].visited = true;
	visited = 1;

	while(visited < maze.num_of_rows * maze.num_of_cols)

	for (int i = 0; i < maze.num_of_rows; i++)
	{
		for (int i = 0; i < maze.num_of_cols; i++) 
		{


		}
	}

}