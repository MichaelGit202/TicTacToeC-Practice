#include <iostream>
#include "JOEBIDEN.h"
#include "board.h"

using namespace std;

int main()
{   /*
    /////joe biden related content, ignore pls////
    JOEBIDEN joe;
    cout << "joes favorite number: ";
    cout << joe.favNum() << endl;
    joe.sayTheLine();
     
    //JOEBIDEN hunter[9] {};

    //for(size_t i = 1; i < )

    vector<JOEBIDEN> joes(9);

    for (int x = 0; x < joes.size(); x++) {
        cout << joes[x].favNum();
    }
    */

    board board;
    cout << board.getCell(0, 1) << endl;
    board.setCell(0, 1, 1);
    cout << board.getCell(0, 1) << endl;
    

    board.printBoard();

    bool win = false;

    cout << "Welcome to c++ minesweeper, use coordinates to pick a spot, you are figting a random function";

    ///while(win == false) {
     //    cout << "select an x coordinate"
         
    
   // }
    
}

