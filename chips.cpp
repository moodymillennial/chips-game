///////////////////////////////////////////////////////////////////////////////////
// Joshua Stromberg, CSCI 140 Tuesdays at 2pm Lab, Project #2
// Input: Number of chips for pile, number of chips to take
// Output: Player turn, chips in pile, winner, legality of moves
// Description: Through different functions that are callled through the
//              main program, the program is a game of chips. Using formulas
//              to deduct the pile amount from chips taken, checks through bools
//              who the winner is, whose turn it is, and if the move is legal.
///////////////////////////////////////////////////////////////////////////////////
 
 
#include <iostream>
using namespace std;
 
void declareWinner(bool player1Turn);
bool isMoveLegal(int chipstaken, int chipsInPile);
int askMove(bool player1Turn, int chipsInPile);
int initGame();
 
 
 
int main()
{
    bool player1Turn = true; // This variable keeps track of whose turn it is.
    // When true it is player 1’s turn and when
    // false it is player2’s turn.
    bool gameOver = false; // will be set to true once the chips are gone.
    int chipsInPile;
    int chipsTaken;
    chipsInPile = initGame();
    while (gameOver == false)
    {
        chipsTaken = askMove(player1Turn, chipsInPile);
        chipsInPile = chipsInPile - chipsTaken;
        if (chipsInPile == 0)
        {
            gameOver = true;
            declareWinner(player1Turn);
        }
        else
        {
            cout << "There are " << chipsInPile << " chips left. " << endl << endl;
            player1Turn = !player1Turn;
             
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////
// This function is called by the main program once the game is over.
// It outputs a message congratulating the winner player.
// Nothing is returned by this function.
//////////////////////////////////////////////////////////////
void declareWinner(bool player1Turn)
{
    if (player1Turn == true)
         
    {
        cout << "Congratulations Player 1! You won the game of chips! " << endl << endl;
    }
     
    else
         
    {
        cout << "Congratulations Player 2! You won the game of chips! " << endl << endl;
    }
     
}
/////////////////////////////////////////////////////////////////
// This function is called be the ask move function.
//It looks at the number of chips in the pile and the number of chips the
//player wants to take and determines if the proposed move is legal. If
//the proposed move is legal this function will return true and if the
//proposed move is not legal this function will return false.
//Remember, a player must take at least 1 chip and no more than half
//of the chips remaining in the pile unless the pile has only one chip
//left in which case the only legal move is to take the one remaining chip.
////////////////////////////////////////////////////////////////////
bool isMoveLegal(int chipsTaken, int chipsInPile)
{
    if (chipsTaken < 1)
    {
        return false;
    }
    else if ((chipsInPile == 1) && (chipsTaken == 1))
    {
        return true;
    }
    else if (chipsTaken > (chipsInPile / 2))
    {
        return false;
    }
    else if ((chipsTaken <= (chipsInPile /2)))
    {
        return true;
    }
    return false;
}
 
//////////////////////////////////////////////////////////////////////
// This function is called by the main program.
//It asks the correct player how many chips they would
//like to take. Then it calls is move legal which determines if the proposed
//move is legal. If the proposed move is NOT legal then it will print
//out a message saying the move is not legal and it will ask repeatedly until
//the player enters a legal move.
//Once a legal move is entered this function returns the number of chips taken.
////////////////////////////////////////////////////////////////////
int askMove(bool player1Turn, int chipsInPile)
{
    if (player1Turn == true)
    {
        bool bIsALegalMove = false;
        while (!bIsALegalMove)
        {
            cout << "Player 1 - how many chips would you like to take? ";
            int chipsTaken;
            cin >> chipsTaken;
            bIsALegalMove = isMoveLegal(chipsTaken, chipsInPile);
            if (!bIsALegalMove)
            {
                cout << "Sorry that was not a legal move" << endl << "Try again." << endl;
            }
            else
            {
                return chipsTaken;
            }
        }
    }
     
    else
    {
        bool bIsALegalMove = false;
        while (!bIsALegalMove)
        {
            cout << "Player 2 - how many chips would you like to take? ";
            int chipsTaken;
            cin >> chipsTaken;
            bIsALegalMove = isMoveLegal(chipsTaken, chipsInPile);
            if (!bIsALegalMove)
            {
                cout << "Sorry that was not a legal move" << endl << "Try again.";
            }
            else
            {
                return chipsTaken;
            }
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////
// This function is called by the main program.
//It asks the user how many chips are in the pile at the start of the game. If
//the user enters a number less than 2 or greater than 50 it will tell him that
//he must enter a number between 2 and 50.
//Once a valid number of chips is entered the function will return the number of
//chips.
/////////////////////////////////////////////////////////////////////
int initGame()
{
    int chipsInPile;
    while (chipsInPile)
    {
        cout << "How many chips do you want to start with? (2-50 inclusive) ";
        cin >> chipsInPile;
        if ((chipsInPile >=2) && (chipsInPile <= 50))
        {
            return chipsInPile;
        }
        else
        {
            cout << "Sorry you must enter a number between 2 and 50 inclusive Try again " << endl;
             
        }
    }
    return chipsInPile;
}
