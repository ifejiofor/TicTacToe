// This file contains the declaration of class TicTacToeCell

#ifndef TIC_TAC_TOE_CELL_H
#define TIC_TAC_TOE_CELL_H

class TicTacToeCell
{
   public:
      TicTacToeCell();

      char getValue();
      void setValue( char requiredValue );

      bool isOccupied();
      bool isNotOccupied();

   private:
      char value;
};

#endif
