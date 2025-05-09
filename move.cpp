/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
   // start with something
   this->source = Position();
   this->dest   = Position();
}

/***************************************************
 * MOVE : STRING CONSTRUCTOR
 ***************************************************/
Move::Move(char* t)
{
   
   this->source = Position(t[0], t[1]);
   this->dest   = Position(t[2], t[3]);
   this->moveType = MOVE;
}

/***************************************************
 * MOVE : LETTER FROM PIECE TYPE
 * Convert the Piece Type into a letter.
 ***************************************************/
char Move::letterFromPieceType(PieceType pt) const
{
   char letter;
   
   switch (pt)
   {
      case SPACE:
         letter = ' ';
         break;
      case PAWN:
         letter = 'p';
         break;
      case KNIGHT:
         letter = 'n';
         break;
      case BISHOP:
         letter = 'b';
         break;
      case ROOK:
         letter = 'r';
         break;
      case QUEEN:
         letter = 'q';
         break;
      case KING:
         letter = 'k';
         break;
      default:
         letter = '!';
         break;
   }
   return letter;
}

/***************************************************
 * MOVE : PIECE TYPE FROM LETTER
 * convert a letter int a PieceType enum.
 ***************************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{
   PieceType piece;
   switch (letter)
   {
      case ' ':
         piece = SPACE;
         break;
      case 'p':
         piece = PAWN;
         break;
      case 'b':
         piece = BISHOP;
         break;
      case 'n':
         piece = KNIGHT;
         break;
      case 'r':
         piece = ROOK;
         break;
      case 'q':
         piece = QUEEN;
         break;
      case 'k':
         piece = KING;
         break;
      default:
         piece = INVALID;
         break;
   }
   return piece;
}

/***************************************************
 * MOVE : EQUALS - EQUALS OPERATOR
 ***************************************************/
//bool Move::operator==(Move &rhs) {
//   return source.getLocation() == rhs.source.getLocation() &&
//          dest.getLocation() == rhs.dest.getLocation(); // &&
//          promote == rhs.promote &&
//          capture == rhs.capture &&
//          moveType == rhs.moveType &&
//          (isWhite == rhs.isWhite) &&
//          text == rhs.text;
//}
