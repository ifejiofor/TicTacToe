
#include <iostream>
#include <iomanip>
#include <string>
#include "TicTacToeBoard.h"
#include "TicTacToeCell.h"
#include "TicTacToePlayer.h"
#include "usefulFunctions.h"
#include "main.h"

using namespace std;


int main()
{
   TicTacToePlayer *pointerToWinner = NULL;
   char userChoice;

   TicTacToePlayer player1 = initializePlayer1();
   TicTacToePlayer player2 = initializePlayer2();

   TicTacToePlayer* pointerToPlayer1 = &player1;
   TicTacToePlayer* pointerToPlayer2 = &player2;

   do {
      pointerToWinner = keepPlayingTicTacToeGameUntilAPlayerWins( pointerToPlayer1, pointerToPlayer2 );
      cout << pointerToWinner->getName() << " won the game!" << endl;
      pointerToWinner->incrementNumberOfWins();

      cout << "\nDo you want to play another game?\n   Enter 'Y' for yes\n   Enter 'N' for no" << endl;
      cin >> userChoice;

      swapPlayers( &pointerToPlayer1, &pointerToPlayer2 );
   } while ( userChoice == 'Y' );

   printResultOfGame( pointerToPlayer1, pointerToPlayer2 );

   return 0;
}


TicTacToePlayer initializePlayer1()
{
   TicTacToePlayer player;
   string name;

   cout << "Please, enter the name of the first player: ";
   cin >> name;

   player.setName( name );
   player.setSymbol( 'X' );

   return player;
}


TicTacToePlayer initializePlayer2()
{
   TicTacToePlayer player;
   string name;

   cout << "Please enter the name of the second player: ";
   cin >> name;

   player.setName( name );
   player.setSymbol( 'O' );

   return player;
}


TicTacToePlayer* keepPlayingTicTacToeGameUntilAPlayerWins( TicTacToePlayer* player1, TicTacToePlayer* player2 )
{
   TicTacToeBoard ticTacToeBoard;
   TicTacToePlayer *currentPlayer, *winner;

   currentPlayer = player1;
   ticTacToeBoard.display();

   while ( true ) {
      allowPlayerToPlayGame( currentPlayer, &ticTacToeBoard );
      indicateWhetherThereHasBeenADraw( &ticTacToeBoard );

      if ( ticTacToeBoard.gameHasBeenWon() ) {
         winner = currentPlayer;
         break;
      }
      else {
         currentPlayer = advanceToNextPlayer( currentPlayer, player1, player2 );
      }
   }

   return winner;
}


void allowPlayerToPlayGame( TicTacToePlayer* currentPlayer, TicTacToeBoard* ticTacToeBoard )
{
   TicTacToeCell& cell = getCellWherePlayerWantsToPlayGame( currentPlayer, ticTacToeBoard );
   markCellToIndicateThatPlayerHasPlayedGameInThatCell( cell, currentPlayer );
   ticTacToeBoard->display();
}


TicTacToeCell& getCellWherePlayerWantsToPlayGame( TicTacToePlayer* pointerToCurrentPlayer, 
   TicTacToeBoard* pointerToTicTacToeBoard )
{
   int row;
   char column;

   displayMessageThatIndicatesWhichPlayerIsToPlay( pointerToCurrentPlayer );

   row = allowPlayerToSpecifyRowWhereHeWantsToPlayGame();
   column = allowPlayerToSpecifyColumnWhereHeWantsToPlayGame();

   while ( theRowAndColumnWherePlayerWantsToPlayGameRepresentAnInvalidCell( row, column, pointerToTicTacToeBoard ) ) {
      displayAppropriateErrorMessage( row, column, pointerToTicTacToeBoard );
      pointerToTicTacToeBoard->display();
      displayMessageThatIndicatesWhichPlayerIsToPlay( pointerToCurrentPlayer );

      row = allowPlayerToSpecifyRowWhereHeWantsToPlayGame();
      column = allowPlayerToSpecifyColumnWhereHeWantsToPlayGame();
   }

   return pointerToTicTacToeBoard->getCell( row, column );
}


void displayMessageThatIndicatesWhichPlayerIsToPlay( TicTacToePlayer* currentPlayer )
{
   cout << currentPlayer->getName() << ", it's your turn to play." << endl;
}


int allowPlayerToSpecifyRowWhereHeWantsToPlayGame()
{
   char row;

   cout << "   Select row (1, 2, or 3): ";
   cin >> row;

   return row - '0';
}


char allowPlayerToSpecifyColumnWhereHeWantsToPlayGame()
{
   char column;

   cout << "   Select column (A, B, or C): ";
   cin >> column;

   return column;
}


bool theRowAndColumnWherePlayerWantsToPlayGameRepresentAnInvalidCell( int row, char column, 
   TicTacToeBoard* ticTacToeBoard )
{
   if ( isNotValidRow( row ) || isNotValidColumn( column ) ) {
      return true;
   }
   else {
      TicTacToeCell& requiredCell = ticTacToeBoard->getCell( row, column );

      if ( requiredCell.isOccupied() ) {
         return true;
      }
   }

   return false;
}


void displayAppropriateErrorMessage( int row, char column, TicTacToeBoard* ticTacToeBoard )
{
   if ( isNotValidRow( row ) ) {
      cout << "Invalid row: Valid rows are 1, 2, and 3." << endl;
   }
   else if ( isNotValidColumn( column ) ) {
      cout << "Invalid column: Valid columns are A, B, and C." << endl;
   }
   else {
      TicTacToeCell& requiredCell = ticTacToeBoard->getCell( row, column );

      if ( requiredCell.isOccupied() ) {
         cout << "The cell you selected is already occupied." << endl;
      }
   }
}


void markCellToIndicateThatPlayerHasPlayedGameInThatCell( TicTacToeCell& cell, TicTacToePlayer* currentPlayer )
{
   cell.setValue( currentPlayer->getSymbol() );
}


void indicateWhetherThereHasBeenADraw( TicTacToeBoard* ticTacToeBoard )
{
   if ( ticTacToeBoard->allCellsAreOccupied() ) {
      TicTacToePlayer::incrementNumberOfDraws();
      cout << "Draw!" << endl;
      // TODO: I hope to place a function that delays for some time here
      cout << "Resetting the board..." << endl;
      ticTacToeBoard->reset();
      ticTacToeBoard->display();
   }
}


TicTacToePlayer* advanceToNextPlayer( TicTacToePlayer* currentPlayer, 
   TicTacToePlayer* player1, TicTacToePlayer* player2 )
{
   TicTacToePlayer* nextPlayer = NULL;

   if ( currentPlayer == player1 ) {
      nextPlayer = player2;
   }
   else if ( currentPlayer == player2 ) {
      nextPlayer = player1;
   }

   return nextPlayer;
}


void swapPlayers( TicTacToePlayer** player1, TicTacToePlayer** player2 )
{
   TicTacToePlayer* temp = *player1;
   *player1 = *player2;
   *player2 = temp;
}


void printResultOfGame( TicTacToePlayer* player1, TicTacToePlayer* player2 )
{
   cout << "\nWow! What a great game!\nBelow is the result of this game:\n\n";

   cout <<
      "++++++++++++++++++++++++++++++++++++++++++\n" <<
      player1->getName() << " won " << player1->getNumberOfWins() << " games\n" <<
      player2->getName() << " won " << player2->getNumberOfWins() << " games\n" <<
      player1->getName() << " and " << player2->getName() << " drew " <<
         TicTacToePlayer::getNumberOfDraws() << " games\n" <<
      "Total number of games played: " <<
         player1->getNumberOfWins() + player2->getNumberOfWins() + TicTacToePlayer::getNumberOfDraws() <<
      "\n++++++++++++++++++++++++++++++++++++++++++\n";
}
