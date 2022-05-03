#pragma once
class player
{
private:
	bool ai = false;
	int plNum;
	int random(int min, int max);
	int max;
public:
	int* pick();

	int getPlayerNum();

	player();

	player(int num, int rngMax) {
		plNum = num;
		max = rngMax - 1;
	}

	player(int num, int rngMax, bool isAi) {
		plNum = num;
		ai = isAi;
		max = rngMax - 1;
	}
		
	//player(bool isAi) : player(int num) {
//
	//}
		
};

