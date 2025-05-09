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
 * MOVE : PARSE
 ***************************************************/
void Move::parse(char* t)
{
   // Convert char* to string and start the iterator.
   string text(t);
   string::const_iterator it = text.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;
   this->source.setCol(col);
   this->source.setRow(row);

   // get the destination
   col = *it - 'a';
   it++;
   row = *it - '1';
   it++;
   this->dest.setCol(col);
   this->dest.setRow(row);
   
   // If there is not more text, then the moveType is Move.
   if (it != text.end())
   {
      // capture and promotion information
      switch (*it)
      {
            // Captures
         case 'p':   // capture a pawn
            this->capture = PAWN;
            this->moveType = MOVE;
            break;
         case 'n':   // capture a knight
            this->capture = KNIGHT;
            this->moveType = MOVE;
            break;
         case 'b':   // capture a bishop
            this->capture = BISHOP;
            this->moveType = MOVE;
            break;
         case 'r':   // capture a rook
            this->capture = ROOK;
            this->moveType = MOVE;
            break;
         case 'q':   // capture a queen
            this->capture = QUEEN;
            this->moveType = MOVE;
            break;
         case 'k':   // !! you can't capture a king you silly!
            this->capture = KING;
            this->moveType = MOVE;
            break;
            
            // Castling & En-Passant
         case 'c':  // short castling or king's castle
            this->moveType = CASTLE_KING;
            break;
         case 'C':  // long castling or queen's castle
            this->moveType = CASTLE_QUEEN;
            break;
         case 'E':  // En-passant
            this->moveType = ENPASSANT;
            break;
            
            // Promotion
         case 'N':  // Promote to knight
            this->promote = KNIGHT;
            this->moveType = MOVE;
            break;
         case 'B':  // Promote to Bishop
            this->promote = BISHOP;
            this->moveType = MOVE;
            break;
         case 'R':  // Promote to Rook
            this->promote = ROOK;
            this->moveType = MOVE;
            break;
         case 'Q':  // Promote to Queen
            this->promote = QUEEN;
            this->moveType = MOVE;
            break;
            
            // This shouldnt happen.
         default:
            this->moveType = MOVE_ERROR;
            break;
      }
   }
   else
   {
      this->moveType = MOVE;
   }
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

