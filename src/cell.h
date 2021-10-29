#pragma once
#include <vector>

class Cell
{
public:
	bool walls[4] = { false, false, false, false };  // index 0 is top and move clockwise
	int x;
	int y;
	bool visited = false;

	Cell(int x_coord, int y_coord)
	{
		x = x_coord;
		y = y_coord;
	}
	
	Cell() = default;
};

