// This file contains the definitions of all the member functions of TicTacToeBoard

#include <iostream>
using namespace std;

#include "TicTacToeBoard.h"
#include "usefulFunctions.h"
#include "usefulConstants.h"


TicTacToeBoard::TicTacToeBoard()
{

}


void TicTacToeBoard::reset()
{
   for ( int i = 0; i < 3; i++ ) {

      for ( int j = 0; j < 3; j++ ) {
         board[i][j].setValue( DEFAULT_CELL_VALUE );
      }
   }

}


void TicTacToeBoard::display()
{
   cout << "\n  A   B   C \n\n" <<
      "1 " << board[0][0].getValue() << " | " << board[0][1].getValue() << " | " << board[0][2].getValue() << "\n" <<
      " ___________\n" <<
      "2 " << board[1][0].getValue() << " | " << board[1][1].getValue() << " | " << board[1][2].getValue() << "\n" <<
      " ___________\n" <<
      "3 " << board[2][0].getValue() << " | " << board[2][1].getValue() << " | " << board[2][2].getValue() << "\n" <<
      endl;
}


TicTacToeCell& TicTacToeBoard::getCell( int row, char column )
{
   if ( isNotValidRow( row ) || isNotValidColumn( column ) ) {
      return board[0][0];
   }

   int indexOfRow = getIndexOfRow( row );
   int indexOfColumn = getIndexOfColumn( column );
   return board[indexOfRow][indexOfColumn];
}


int TicTacToeBoard::getIndexOfRow( int row )
{
   return row - 1;
}


int TicTacToeBoard::getIndexOfColumn( char column )
{
   return column - 'A';
}


bool TicTacToeBoard::gameHasNotBeenWon()
{
   return !gameHasBeenWon();
}


bool TicTacToeBoard::gameHasBeenWon()
{
   return gameHasBeenWonHorizontally() || gameHasBeenWonVertically() || gameHasBeenWonDiagonally();
}


bool TicTacToeBoard::gameHasBeenWonHorizontally()
{
   for ( int indexOfRow = 0; indexOfRow < 3; indexOfRow++ ) {

      if ( board[indexOfRow][0].getValue() != DEFAULT_CELL_VALUE && 
         board[indexOfRow][0].getValue() == board[indexOfRow][1].getValue() && 
         board[indexOfRow][1].getValue() == board[indexOfRow][2].getValue() )
      {
         return true;
      }
   }

   return false;
}


bool TicTacToeBoard::gameHasBeenWonVertically()
{
   for ( int indexOfColumn = 0; indexOfColumn < 3; indexOfColumn++ ) {

      if ( board[0][indexOfColumn].getValue() != DEFAULT_CELL_VALUE &&
         board[0][indexOfColumn].getValue() == board[1][indexOfColumn].getValue() && 
         board[1][indexOfColumn].getValue() == board[2][indexOfColumn].getValue() )
      {
         return true;
      }
   }

   return false;
}


bool TicTacToeBoard::gameHasBeenWonDiagonally()
{
   if ( board[0][0].getValue() != DEFAULT_CELL_VALUE && 
      board[0][0].getValue() == board[1][1].getValue() && 
      board[1][1].getValue() == board[2][2].getValue() )
   {
      return true;
   }

   if ( board[2][0].getValue() != DEFAULT_CELL_VALUE && 
      board[2][0].getValue() == board[1][1].getValue() && 
      board[1][1].getValue() == board[0][2].getValue() )
   {
      return true;
   }

   return false;
}


bool TicTacToeBoard::allCellsAreNotOccupied()
{
   return !allCellsAreOccupied();
}


bool TicTacToeBoard::allCellsAreOccupied()
{
   int numberOfOccupiedCells = 0;

   for ( int i = 0; i < 3; i++ ) {

      for ( int j = 0; j < 3; j++ ) {

         if ( board[i][j].getValue() != DEFAULT_CELL_VALUE ) {
            numberOfOccupiedCells++;
         }
      }
   }

   return numberOfOccupiedCells == 9;
}
