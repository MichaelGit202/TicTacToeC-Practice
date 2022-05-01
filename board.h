#pragma once
#include "cell.h";
#include "player.h";
#include <vector>
class board
{
	private: 
		bool win = false;
		vector<vector<cell>>tiles;
		int setCell(int x, int y, int player);
		player winner = NULL;
		player winningMove(int x, int y , player player);
		void setWinner(player player);

	public:
			//giving the board the ability to check for a winner may be excessive
			//however I already print with it so idk
		bool getWin();
		player getWinner();
		string getCell(int x, int y);
		int pickCell(player &player);
		board();
		void printBoard();
		int* getSize();

};

