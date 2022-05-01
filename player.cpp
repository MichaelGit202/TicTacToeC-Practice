#include "player.h"
#include <iostream>
using namespace std;

int * player::pick() {
    int x, y = 0;
    if (this->ai == false) {
        cout << "pick a space" << endl;
        cout << "select a X coordinate: " << endl;
        try {
            cin >> x;
            cout << "select a Y coordinate: " << endl;
            cin >> y;
        }catch(exception e) {
            cout << "invalid input";
            x = -1;
            y = -1;
        }

    }
    else {
        cout << "is an ai" << endl;
        x = random(0, 2);   
        y = random(0, 2);
        cout << x; cout << ", "; cout << y << endl;
    }        
    
    int tmp[2] = {x,y};
    return tmp;
}


int player::getPlayerNum() {
    return plNum;
}



int player::random(int min, int max) {

    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }

    return min + rand() % ((max + 1) - min);
}