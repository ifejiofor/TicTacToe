// This file contains the definitions of the member functions of class TicTacToePlayer,
// as well as, the initialization of its static data member

#include "TicTacToePlayer.h"


int TicTacToePlayer::numberOfDraws = 0;


TicTacToePlayer::TicTacToePlayer()
{
   numberOfWins = 0;
}


void TicTacToePlayer::setName( string name )
{
   nameOfPlayer = name;
}


void TicTacToePlayer::setSymbol( char symbol )
{
   symbolOfPlayer = symbol;
}


void TicTacToePlayer::incrementNumberOfWins()
{
   numberOfWins++;
}


void TicTacToePlayer::incrementNumberOfDraws()
{
   numberOfDraws++;
}


string TicTacToePlayer::getName()
{
   return nameOfPlayer;
}


char TicTacToePlayer::getSymbol()
{
   return symbolOfPlayer;
}


int TicTacToePlayer::getNumberOfWins()
{
   return numberOfWins;
}


int TicTacToePlayer::getNumberOfDraws()
{
   return numberOfDraws;
}
