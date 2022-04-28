#include "cell.h"
using namespace std;


string cell::getState() {
	switch (this->state)  //this warning literally means nothing
	{
	case X:
		return " X ";
	case O:
		return " O ";
	case E:
		return "   ";
	default:
		return "   ";
	}
	

}

void cell::setState() {
	switch (this->state)  //this warning literally means nothing
	{
	case X:
		state = this-> X;
	case O:
		 " O ";
	case E:
		 "   ";
	default:
		 "   ";
	}


}
