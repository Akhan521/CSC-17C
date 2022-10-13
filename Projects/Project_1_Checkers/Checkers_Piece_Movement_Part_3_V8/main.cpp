/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: Oct. 12, 2022, 1:50 PM
 * Purpose: Version 8 - Piece Movement Part 3. 
 * 
 *  Adding functionality to capture pieces on our board. If we can jump a 
 *  piece, we capture it. As long as we can continue jumping pieces, we have
 *  to capture all possible pieces until we can no longer capture any pieces.
 *  This is, by far, the most important functionality since it defines how 
 *  players can capture opponent pieces and win the game.
 */

//System Libraries:

//User Libraries:
#include "Board.h"

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Creating a board object.
    Board *board=new Board();
    
    //Displaying our board.
    cout<<"A checkers board: "<<endl<<endl;
    board->dsplyBrd();
    
    //Moving 1 piece.
    board->move();
    board->dsplyBrd();
    
    //Moving another piece.
    board->move();
    board->dsplyBrd();
    
    //Moving a 3rd piece.
    board->move();
    board->dsplyBrd();
    
    //Exit the Program - Cleanup.
    delete board;
    return 0;
}