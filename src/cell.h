#pragma once

class Cell
{
public:
	bool walls[4] = { true, true, true, true };  // index 0 is top and move clockwise
	int x;
	int y;
	bool visited = false;
	bool inpath = false;

	Cell(int x_coord, int y_coord)
	{
		x = x_coord;
		y = y_coord;
	}
};

