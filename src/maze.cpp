#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include "maze.h"
#include "time.h"


Maze::Maze(int rows, int cols) {
	width = cols;
	height = rows;
	initialise();
}

void Maze::initialise() {
	for (int x = 0; x < width; x++) {
		std::vector<Cell> col_vec;

		for (int y = 0; y < width; y++) {
			col_vec.push_back(Cell(x, y));
		}
		cells.push_back(col_vec);
	}
	return;
}

void Maze::draw_maze() {

	std::stack<Cell*> my_stack;
	my_stack.push(&cells[0][0]);
	int visited = 1;

	srand(time(NULL));


	while (visited < width * height) {

		std::vector<int> neighbours;

		auto current = my_stack.top();
		current->visited = true;

		//std::cout << "visting (" << current->x << "," << current->y << ")" << std::endl;

		// check northern neighbour
		if (current->y > 0 && cells[current->x][current->y - 1].visited == false) {
			neighbours.push_back(0);
		}

		// check eastern neighbour
		if (current->x < width - 1 && cells[current->x + 1][current->y].visited == false) {
			neighbours.push_back(1);
		}

		// check southern neighbour
		if (current->y < height - 1 && cells[current->x][current->y + 1].visited == false) {
			neighbours.push_back(2);
		}

		// check western neighbour
		if (current->x > 0 && cells[current->x - 1][current->y].visited == false) {
			neighbours.push_back(3);
		}

		if (!neighbours.empty()) {

			int next_cell_dir = neighbours[rand() % neighbours.size()];

			switch (next_cell_dir) {

			case 0:   // northern neighbour
				my_stack.push(&cells[current->x][current->y - 1]);

				cells[current->x][current->y].walls[0] = false;
				cells[current->x][current->y - 1].walls[2] = false;

				break;

			case 1:  // eastern neighbour
				my_stack.push(&cells[current->x + 1][current->y]);

				cells[current->x][current->y].walls[1] = false;
				cells[current->x + 1][current->y].walls[3] = false;


				break;

			case 2:  // southern neighbour
				my_stack.push(&cells[current->x][current->y + 1]);

				cells[current->x][current->y].walls[2] = false;
				cells[current->x][current->y + 1].walls[0] = false;

				break;

			case 3:  // western neighbour
				my_stack.push(&cells[current->x - 1][current->y]);

				cells[current->x][current->y].walls[3] = false;
				cells[current->x - 1][current->y].walls[1] = false;

				break;
			}

			visited++;
		}

		else {
			my_stack.pop();
		}
	}

}

void Maze::print_maze() {
	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			std::cout << "+";

			if (cells[x][y].walls[0])
				std::cout << "---";

			else
				std::cout << "   ";

		}

		std::cout << "+";

		std::cout << std::endl;

		for (int x = 0; x < width; x++) {



			if (cells[x][y].walls[3])
				std::cout << "|";

			else {

				std::cout << " ";
			}

			if (cells[x][y].inpath) {

				std::cout << " . ";
			}
			else {
				std::cout << "   ";

			}


		}

		std::cout << "|";


		std::cout << std::endl;


	}

	for (int x = 0; x < width; x++) {

		std::cout << "+---";
	}

	std::cout << "+" << std::endl;

}

void Maze::reset_visited() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < width; y++) {
			cells[x][y].visited = false;
		}
	}

}
bool Maze::path_find(int start_x, int start_y, const int end_x, const int end_y) {

 	Cell& current = cells[start_x][start_y];
	current.visited = true;
	cells[0][0].inpath = true;

	if (start_x == end_x && start_y == end_y) {
		return true;
	}

	std::vector<Cell*> neighbours;

	// check northern neighbour
	if (!current.walls[0])
		neighbours.push_back(&cells[current.x][current.y - 1]);

	// check eastern neighbour
	if (!current.walls[1])
		neighbours.push_back(&cells[current.x + 1][current.y]);

	// check southern neighbour
	if (!current.walls[2])
		neighbours.push_back(&cells[current.x][current.y + 1]);

	// check western neighbour
	if (!current.walls[3])
		neighbours.push_back(&cells[current.x - 1][current.y]);

	for (auto cell : neighbours) {
		if (!cell->visited) {
			if (path_find(cell->x, cell->y, end_x, end_y)) {
				cell->inpath = true;
				std::cout << "Visiting..(" << cell->x << "," << cell->y  << ")" << std::endl;
				return true;
			}
			
		}
	}

	current.visited = false;
	return false;
}



