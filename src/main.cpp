#include <iostream>
#include "maze.h"



int main()
{
	int rows = 3;
	int cols = 6;

	Maze my_maze(rows, cols);

	my_maze.draw_maze();
	my_maze.print_maze();
	my_maze.reset_visited();
	bool result = my_maze.path_find(0, 0, cols -1, rows -1);
	std::cout << result << std::endl;
}
