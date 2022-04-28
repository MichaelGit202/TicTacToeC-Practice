#include "board.h"
using namespace std;

board::board() {
	//default constuctor

}


string board::getCell(int x, int y) {
	return this->tiles[x + y].getState();
}


	