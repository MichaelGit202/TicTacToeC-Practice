#include "cell.h"
using namespace std;

string cell::getState() {
	switch (state)
	{
	case X:
		return "joe";
	case O:
		return "mom";
	case E:
		return "ma";
	default:
		return "nosout";
	}
	

}
