#include <iostream>
#include "JOEBIDEN.h"
#include "board.h"
void playerTurn(board& board, player& player);
bool checkwin(board& board, player& player);

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
    
     //picks a spot succsesfully
    cout << "Welcome to c++ minesweeper, use coordinates to pick a spot, you are figting a random function" << endl;

    board.printBoard();
    player playerOne(0);
    player playerTwo(1, true);
    vector<player> players;
    players.push_back(playerOne);
    players.push_back(playerTwo);

    while (win == false) {
        for (player pl : players) {
            cout << "player "; cout << pl.getPlayerNum(); cout << "'s turn" << endl;
            playerTurn(board, pl);
        }
    }

    
}


//bool checkwin(board &board, player &player) {
    //int* sz[2] = { board.getSize() };
    // 
    //for (int* i = 0; i < sz[0]; i++)
    //{
    //    for (int* j = 0; i < sz[1]; i++)
    //    {
    //
    //    }
    //
    //}
    


//}



void playerTurn(board &board, player &player) {
    int pick = -1;

    do{

        pick  = board.pickCell(player);
        if (pick == -1) {
            cout << "That is not a valid input try again" << endl;

        }

    }while(pick == -1);
    board.printBoard();
}



