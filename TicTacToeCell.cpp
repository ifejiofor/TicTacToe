// This file contains the definitions of all member functions of TicTacToeCell

#include "TicTacToeCell.h"
#include "usefulConstants.h"


TicTacToeCell::TicTacToeCell()
{
   value = DEFAULT_CELL_VALUE;
}


char TicTacToeCell::getValue()
{
   return value;
}


void TicTacToeCell::setValue( char requiredValue )
{
   value = requiredValue;
}


bool TicTacToeCell::isOccupied()
{
   return !isNotOccupied();
}


bool TicTacToeCell::isNotOccupied()
{
   return value == DEFAULT_CELL_VALUE;
}
