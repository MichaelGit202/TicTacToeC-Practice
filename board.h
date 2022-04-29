#pragma once
#include "cell.h";
#include <vector>
class board
{
	private: 
		vector<vector<cell>>tiles;

	public:
		string getCell(int x, int y);
		int setCell(int x, int y, int player);
		board();
		void printBoard();

};

