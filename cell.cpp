#include "cell.h"
using namespace std;


string cell::getState() {
	switch (this->state)  //this warning literally means nothing
	{
	case X:
		return "X";
	case O:
		return "O";
	case E:
		return " ";
	default:
		return " ";
	}
	

}

void cell::setState(int set) {	
	switch (set)  //this warning literally means nothing
	{
	case 0:
		this->state = X;
	case 1:
		this->state = O;
	}

}
