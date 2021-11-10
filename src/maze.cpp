#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include "maze.h"


Maze::Maze(int rows, int cols) {
	width = cols;
	height = rows;
	this->initialise();
}

void Maze::draw_maze() {

	std::stack<Cell*> my_stack;
	my_stack.push(&cells[0][0]);
	int visited = 1;


	while (visited < width * height) {

		std::vector<int> neighbours;

		auto current = my_stack.top();
		current->visited = true;

		std::cout << "visting (" << current->x << "," << current->y << ")" << std::endl;

		// check western neighbour
		if (current->y > 0 && cells[current->x][current->y - 1].visited == false) {
			neighbours.push_back(0);
		}

		// check southern neighbour
		if (current->x < height - 1 && cells[current->x + 1][current->y].visited == false) {
			neighbours.push_back(1);
		}

		// check eastern neighbour
		if (current->y < width - 1 && cells[current->x][current->y + 1].visited == false) {
			neighbours.push_back(2);
		}

		// check northern neighbour
		if (current->x > 0 && cells[current->x - 1][current->y].visited == false) {
			neighbours.push_back(3);
		}


		if (!neighbours.empty()) {

			int next_cell_dir = neighbours[rand() % neighbours.size()];

			switch (next_cell_dir) {

			case 0:   // western neighbour
				my_stack.push(&cells[current->x][current->y - 1]);

				cells[current->x][current->y].walls[3] = false;
				cells[current->x][current->y - 1].walls[1] = false;

				break;

			case 1:  // southern neighbour
				my_stack.push(&cells[current->x + 1][current->y]);

				cells[current->x][current->y].walls[2] = false;
				cells[current->x + 1][current->y].walls[0] = false;

				break;

			case 2:  // eastern neighbour
				my_stack.push(&cells[current->x][current->y + 1]);

				cells[current->x][current->y].walls[1] = false;
				cells[current->x][current->y + 1].walls[3] = false;

				break;

			case 3:  // northern neighbour
				my_stack.push(&cells[current->x - 1][current->y]);

				cells[current->x][current->y].walls[0] = false;
				cells[current->x - 1][current->y].walls[2] = false;

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
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {

			std::cout << "+";

			if (cells[i][j].walls[0])
				std::cout << "---";

			else
				std::cout << "   ";

		}

		std::cout << "+";

		std::cout << std::endl;

		for (int j = 0; j < width; j++) {

			if (cells[i][j].walls[3])
				std::cout << "|   ";

			else
				std::cout << "    ";
		}

		std::cout << "|";


		std::cout << std::endl;


	}

	for (int j = 0; j < width; j++) {

		std::cout << "+---";
	}

	std::cout << "+";

}


void Maze::initialise() {
	for (int i = 0; i < height; i++) {
		std::vector<Cell> row_vec;

		for (int j = 0; j < width; j++) {
			row_vec.push_back(Cell(i, j));
		}
		cells.push_back(row_vec);
	}
	return;
}

