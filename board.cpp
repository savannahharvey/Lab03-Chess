/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "position.h"
#include "piece.h"
#include <cassert>
using namespace std;


/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   int col = pos.getCol();
   int row = pos.getRow();

   return *board[col][row];
}
Piece& Board::operator [] (const Position& pos)
{
   int col = pos.getCol();
   int row = pos.getRow();

   return *board[col][row];
}


/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr)
{
   pSpace = new Space;
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}