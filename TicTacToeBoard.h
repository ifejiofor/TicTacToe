// This file contains the declaration of class TicTacToeBoard

#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include "TicTacToeCell.h"


class TicTacToeBoard
{
   public:
      TicTacToeBoard();
      void reset();
      void display();

      TicTacToeCell& getCell( int row, char column );

      bool gameHasNotBeenWon();
      bool gameHasBeenWon();
      bool allCellsAreNotOccupied();
      bool allCellsAreOccupied();

   private:
      int getIndexOfRow( int row );
      int getIndexOfColumn( char column );

      bool gameHasBeenWonHorizontally();
      bool gameHasBeenWonVertically();
      bool gameHasBeenWonDiagonally();

      TicTacToeCell board[3][3];
};

#endif
