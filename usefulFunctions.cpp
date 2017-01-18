// This file contains the definintions of some functions that may come handy while using the TicTacToeBoard

#include "usefulFunctions.h"

bool isNotValidRow( int row )
{
   return !isValidRow( row );
}


bool isValidRow( int row )
{
   return row == 1 || row == 2 || row == 3;
}


bool isNotValidColumn( char column )
{
   return !isValidColumn( column );
}


bool isValidColumn( char column )
{
   return column == 'A' || column == 'B' || column == 'C';
}
