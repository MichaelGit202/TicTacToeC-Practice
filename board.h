#pragma once
#include "NCell.h";
#include <vector>
class board
{
	private: 
		 vector<NCell> tiles;

	public:
		string getCell(int x, int y);
		void setCell(int x, int y, string value);

};

