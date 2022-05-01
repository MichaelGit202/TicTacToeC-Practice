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
	
	if (x > -1 && x > -1 && y < tiles.size() && x < tiles[0].size() - 1 && y < tiles.size() - 1
		&& tiles[y][x].getState() == " ")
	{
		tiles[y][x].setState(player);
		return 0;
	}
	else {
		return -1;
	}
}


int board::pickCell(player& player) {
    int* select = player.pick();
	winningMove(select[0], select[1],player);
	//winningMove(select[0], select[1], player); //this is not ok because it sends the pointer for whatever reason
	return this->setCell(select[0], select[1], player.getPlayerNum());	//but it works here?, I think its because the other one 
}																		//returns to here

int* board::getSize() {
	int tmp[2] = {tiles.size(), tiles[0].size()};
	return tmp;
}


void board::setWinner(player& player) {
	this->winner = player;
}

int board::winningMove(int x, int y , player player) {
	//check all around x,y for player symbol and if found check in that same
	//direction for 1 more player symbol

	string plState = "";
	if (player.getPlayerNum() == 0) {	//had to do this jank
		plState = "X";					//because this is defined on a cell
	}									//level only, ie the player object
	else if (player.getPlayerNum() == 1) {	//does not know what it is other than player num
		plState = "O";						//and cell is the only interpreter for what each
	}										//playernum should look like

	int* max = this->getSize(); //y, x


	//sometimes you just wana make a lot of if's with only 2 ifs
	vector<vector<int>> instructions = { {-1,-1},{-1,0},{0,-1},{-1,1},{1,-1},{0,1},{1,0},{1,1} };
	for (vector<int> i : instructions)
	{
		//eye vomit
		if ( x  - i[1] > 0 &&  y  - i[0] > 0 &&  x  < max[1] - i[1] &&  y  < max[0] - i[0] && tiles[ y  - i[0]][ x  - i[1]].getState() == plState) {
			if ( x  - (i[1]* 2) > 0 &&  y - (i[0] * 2) > 0 &&  y < max[1] - (i[1] * 2) &&  y < max[0] - (i[0] * 2) && tiles[ y  - (i[0] * 2)][ x  - (i[1] * 2)].getState() == plState) {
				cout << "yea you won" << endl;
				//return true;
			}
		}
	}

	return false;
}

void board::printBoard() {
	
	cout << "-------------" << endl;

	for (vector<cell>& v : tiles) {
		cout << "| ";
		for (cell& c : v) {
			cout << c.getState() + " | ";
		}
	cout << endl;
	cout << "-------------" << endl;
	}


}

	