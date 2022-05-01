#pragma once
#include "cell.h";
#include "player.h";
#include <vector>
class board
{
	private: 
		vector<vector<cell>>tiles;
		int setCell(int x, int y, int player);
		player winner = NULL;
		int winningMove(int x, int y , player player);

	public:
			//giving the board the ability to check for a winner may be excessive
			//however I already print with it so idk
		
		void setWinner(player& player);
		string getCell(int x, int y);
		int pickCell(player &player);
		board();
		void printBoard();
		int* getSize();

};

