// This file contains prototypes of the functions defined in the file "main.c"

#ifndef MAIN_H
#define MAIN_H

TicTacToePlayer initializePlayer1();

TicTacToePlayer initializePlayer2();

TicTacToePlayer* keepPlayingTicTacToeGameUntilAPlayerWins( 
   TicTacToePlayer* pointerToPlayer1, TicTacToePlayer* pointerToPlayer2 );

void allowPlayerToPlayGame( TicTacToePlayer* currentPlayer, TicTacToeBoard* ticTacToeBoard );

void indicateWhetherThereHasBeenADraw( TicTacToeBoard* ticTacToeBoard );

TicTacToePlayer* advanceToNextPlayer( 
   TicTacToePlayer* currentPlayer, TicTacToePlayer* player1, TicTacToePlayer* player2 );

TicTacToeCell& getCellWherePlayerWantsToPlayGame( TicTacToePlayer* pointerToCurrentPlayer, 
   TicTacToeBoard* ticTacToeBoard );

void displayMessageThatIndicatesWhichPlayerIsToPlay( TicTacToePlayer* currentPlayer );

int allowPlayerToSpecifyRowWhereHeWantsToPlayGame();

char allowPlayerToSpecifyColumnWhereHeWantsToPlayGame();

bool theRowAndColumnWherePlayerWantsToPlayGameRepresentAnInvalidCell( int row, char column,
   TicTacToeBoard* ticTacToeBoard );

void displayAppropriateErrorMessage( int row, char column, TicTacToeBoard* board );

void markCellToIndicateThatPlayerHasPlayedGameInThatCell( TicTacToeCell& cell, TicTacToePlayer* currentPlayer );

void swapPlayers( TicTacToePlayer** player1, TicTacToePlayer** player2 );

void printResultOfGame( TicTacToePlayer* player1, TicTacToePlayer* player2 );

#endif
