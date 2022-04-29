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
    // cout << board.getCell(0, 1) << endl;
    //board.setCell(0, 1, 1);
    //cout << board.getCell(0, 1) << endl;
    


    bool win = false;
    int x, y = 0;
     //picks a spot succsesfully
    cout << "Welcome to c++ minesweeper, use coordinates to pick a spot, you are figting a random function" << endl;

    board.printBoard();

    while (win == false) {
        cout << "pick a space" << endl;
        cout << "select a X coordinate: " << endl;
        cin >> x;
        cout << "select a Y coordinate: " << endl;
        cin >> y;
        playerTurn(0, x, y, board);
        playerTurn(1, random(0,3), random(0,3), board);

    }

    
}


void playerTurn(int player, int x, int y, board &board) {
    int pick = -1;

    do{

        pick  = board.setCell(y - 1, x - 1, 0);
        if (pick == -1) {
            cout << x + ", " + y; cout << "is not a valid input" << endl;

        }
    }while(pick = - 1);
    board.printBoard();
}


int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }

    return min + rand() % ((max + 1) - min);
}
