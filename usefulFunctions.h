// This file contains the declarations of some functions that may come handy while using the TicTacToeBoard.

#ifndef USEFUL_FUNCTIONS_H
#define USEFUL_FUNCTIONS_H

bool isNotValidRow( int row );
bool isValidRow( int row );  // A row is valid if it is either 1, 2, or 3.
bool isNotValidColumn( char column );
bool isValidColumn( char column );  // A column is valid if it is either 'A', 'B', or 'C'

#endif
