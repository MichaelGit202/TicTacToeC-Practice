#pragma once
#include "cell.h";
#include <vector>
class board
{
	private: 
		vector<cell>tiles[9];
		board();

	public:
		string getCell(int x, int y);
		void setCell(int x, int y, string value);

};

