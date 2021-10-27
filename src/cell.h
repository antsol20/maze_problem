#pragma once
#include <vector>

class Cell
{
public:
	std::vector<bool> walls;  // index 0 is top and move clockwise
	int x;
	int y;

	Cell(int x_coord, int y_coord)
	{
		x = x_coord;
		y = y_coord;
	}
	
	Cell() = default;
};

