#include "cell.h"
#include <iostream>
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
	case B:
		return "?"; //for errors
	default:
		return " ";
	}
	

}

void cell::setState(int set) {	
	
	switch (set) 
	{
	case 0:
		this->state = X;
		break;
	case 1:
		this->state = O;
		break;
	default:
		this->state = B;
		break;
	}

}
