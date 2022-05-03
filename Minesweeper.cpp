#include <iostream>
#include "JOEBIDEN.h"
#include "board.h"
void playerTurn(board& board, player& player);
bool checkwin(board& board, player& player);

using namespace std;

//to do 
//make expandible - mabey if I care enough 


//notes, should have declared cell states in like board

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


    // cout << board.getCell(0, 1) << endl;
    //board.setCell(0, 1, 1);
    //cout << board.getCell(0, 1) << endl;

    int size;
    cout << "size of the board" << endl;
    cin >> size; 
    board board(size);

    bool win = false;
    cout << "Welcome to c++ minesweeper, use coordinates to pick a spot, you are figting a random function" << endl;

    board.printBoard();
    player playerOne(0, size, true);
    player playerTwo(1, size, true);
    vector<player> players;
    players.push_back(playerOne);
    //players.push_back(playerTwo);
 
    while (win == false) {
        for (player pl : players) {
            cout << "player "; cout << pl.getPlayerNum(); cout << "'s turn" << endl;
            playerTurn(board, pl);

            if (board.getWin()) {
                win = true;
                break;
            }

            if (board.checkDraw()) {
                win = true;
                break;
            }
        }
    }

    if (board.getWin()) {
        cout << "player: ";
      //  player& winner = board.getWinner();
       // cout << winner.getPlayerNum();
        cout << " has won";
    }
    else if (!board.getWin()) {
        cout << "Draw, you both lose" << endl;
    }

}






void playerTurn(board &board, player &player) {
    bool pick = false;
    do{

        pick  = board.pickCell(player);
        if (!pick) {
            cout << "That is not a valid input try again" << endl;

        }

    }while(!pick);
    board.printBoard();
}



