#include <iostream>
#include "maze.h"



int main()
{
	int rows = 5;
	int cols = 8;

	Maze my_maze(rows, cols);

	my_maze.draw_maze();
	my_maze.print_maze();


	
}
