#include "board.h"
#include <iostream>
using namespace std;

board::board() {

	for (int i = 0; i < 3; i++) {
		vector<cell> newVec;
		for (int j = 0; j < 3; j++) {
			cell newCell;
			newVec.push_back(newCell);
		}
			tiles.push_back(newVec);
	}
}


string board::getCell(int x, int y) {
	return this->tiles[y][x].getState();
}

int board::setCell(int x, int y, int player) {
	if (tiles[y][x].getState() == "E") {
		tiles[y][x].setState(player);
		return 0;
	}
	else {
		return -1;
	
	}
}

void board::printBoard() {
	
	cout << "-------------" << endl;

	for (vector<cell> v : tiles) {
		cout << "| ";
		for (cell c : v) {
			cout << c.getState() + " | ";
		}
	cout << endl;
	cout << "-------------" << endl;
	}


}

	