// This file contains the declaration of the class TicTacToePlayer

#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include <string>
using namespace std;

class TicTacToePlayer
{
   public:
      TicTacToePlayer();

      void setName( string name );
      void setSymbol( char symbol );
      void incrementNumberOfWins();
      static void incrementNumberOfDraws();

      string getName();
      char getSymbol();
      int getNumberOfWins();
      static int getNumberOfDraws();

   private:
      string nameOfPlayer;
      char symbolOfPlayer;
      int numberOfWins;
      static int numberOfDraws;
};

#endif
