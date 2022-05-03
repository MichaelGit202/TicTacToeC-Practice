#include "board.h"
#include <iostream>
using namespace std;

board::board(int size) {
	player* p = winner;
	p = NULL;

	for (int i = 0; i < size; i++) {
		vector<cell> newVec;
		for (int j = 0; j < size; j++) {
			cell newCell;
			newVec.push_back(newCell);
		}
			tiles.push_back(newVec);
	}
}


string board::getCell(int x, int y) {
	return this->tiles[y][x].getState();
}

bool board::setCell(int x, int y, int player) {	

	
	
	if (x > -1 && y > -1 && y < tiles.size() && x < tiles[0].size() && y < tiles.size()
		&& tiles[y][x].getState() == " " && tiles[y][x].getState() != "X" && tiles[y][x].getState() != "O")
	{
		this->tiles[y][x].setState(player);
		return true;
	}
	else {
		return false;
	}
}


int board::pickCell(player& player) {
    int* select = player.pick();		//this contains pointers that it passes onto a varible
	int x = select[0];	//pass the pointer onto x & y
	int y = select[1];
	bool setable = this->setCell(x, y, player.getPlayerNum());
	if (setable) {
		this->winningMove(x, y, player);
	}
	//winningMove(select[0], select[1], player); //this is not ok because it sends the pointer but does not retain it
	return setable;	//but it works here?, I think its because the other one 
}																		//returns to here

int* board::getSize() {
	int tmp[2] = {tiles.size(), tiles[0].size()};
	return tmp;
}


void board::setWinner(player* player) {
	this->winner = player;
	this->win = true;
}

bool board::getWin() {
	return this->win;
}

player* board::getWinner() {
	return this->winner;
}



player* board::winningMove(int x, int y , player Player) {
	//check all around x,y for player symbol and if found check in that same
	//direction for 1 more player symbol

	string plState = "";
	if (Player.getPlayerNum() == 0) {	//had to do this jank
		plState = "X";					//because this is defined on a cell
	}									//level only, ie the player object
	else if (Player.getPlayerNum() == 1) {	//does not know what it is other than player num
		plState = "O";						//and cell is the only interpreter for what each
	}										//playernum should look like

	int* max = this->getSize(); //y, x
	int maxX = max[0];
	int maxY = max[1];
	cout << (x < maxY) << endl;
	
	//sometimes you just wana make a lot of if's with only 2 ifs
	vector<vector<int>> instructions = { {-1,-1},{-1,0},{0,-1},{-1,1},{1,-1},{0,1},{1,0},{1,1} };
	for (vector<int> i : instructions)
	{
		//eye vomit
		if ( x + i[1] > -1 &&
			y  + i[0] > -1 &&
			x + i[1] < maxY &&
			y + i[0] < maxX &&
			tiles[ y  + i[0]][ x  + i[1]].getState() == plState){


			if (x + (i[1] * 2) > -1 &&
				y + (i[0] * 2) > -1 &&
				x + (i[1] * 2) < maxY &&
				y + (i[0] * 2) < maxX &&
				tiles[y + (i[0] * 2)][x + (i[1]* 2)].getState() == plState) {
				setWinner(&Player);
				return &Player;
			}

			if (x - i[1] > -1 &&
				y - i[0] > -1 &&
				x - i[1] < maxY &&
				y - i[0] < maxX &&
				tiles[y - i[0]][x - i[1]].getState() == plState) {
				setWinner(&Player);
				return &Player;
			}


		}
	}

	player *p = winner;
	p = NULL;
	return p;
}

bool board::checkDraw() {

	bool fullFlag = true;
	for (vector<cell>& v : tiles) {
		for (cell& c : v) {
			if (c.getState() == " ") {
				bool fullFlag = false;
				return false;
			}
		}

	}

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

	