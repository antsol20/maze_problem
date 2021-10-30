#include <iostream>
#include "maze.h"



int main()
{
	int rows = 4;
	int cols = 4;

	Maze my_maze(rows, cols);

	my_maze.draw_maze();
	
}
