#pragma once
class player
{
private:
	bool ai = false;
	int plNum;
	int random(int min, int max);

public:
	int* pick();

	int getPlayerNum();

	player(int num) {
		plNum = num;
	}

	player(int num, bool isAi) {
		plNum = num;
		ai = isAi;
	}
		
		
		
};

