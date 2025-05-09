/***********************************************************************
 * Header File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#pragma once

#include <cassert>
#include "move.h"   // Because we return a set of Move

class ogstream;
class TestPawn;
class TestKnight;
class TestBishop;
class TestRook;
class TestQueen;
class TestKing;
class TestBoard;
class Position;
class Piece;



/***************************************************
 * BOARD
 * The game board
 **************************************************/
class Board
{
   friend TestPawn;
   friend TestKnight;
   friend TestBishop;
   friend TestRook;
   friend TestQueen;
   friend TestKing;
   friend TestBoard;

public:

   // getters
   virtual int  getCurrentMove() const { return -99;      }
   virtual bool whiteTurn()      const { return false;  }
   virtual void display(const Position& posHover, const Position& posSelect) const {}
   virtual const Piece& operator [] (const Position& pos) const;

   // setters
   virtual void move(const Move & move) { }
   virtual Piece& operator [] (const Position& pos);

protected:
   int numMoves;
   Piece * board[8][8];    // the board of chess pieces
};


/***************************************************
 * BOARD DUMMY BOARD
 * A board double that does nothing but assert. Will need this for unit tests.
 **************************************************/
class BoardDummy : public Board
{
   friend TestBoard; 
public:
    BoardDummy()
    {
        numMoves = 0;
        board[0][0] = nullptr;
        board[1][0] = nullptr;
        board[2][0] = nullptr;
        board[3][0] = nullptr;
        board[4][0] = nullptr;
        board[5][0] = nullptr;
        board[6][0] = nullptr;
        board[7][0] = nullptr;
        board[0][1] = nullptr;
        board[1][1] = nullptr;
        board[2][1] = nullptr;
        board[3][1] = nullptr;
        board[4][1] = nullptr;
        board[5][1] = nullptr;
        board[6][1] = nullptr;
        board[7][1] = nullptr;
        board[0][2] = nullptr;
        board[1][2] = nullptr;
        board[2][2] = nullptr;
        board[3][2] = nullptr;
        board[4][2] = nullptr;
        board[5][2] = nullptr;
        board[6][2] = nullptr;
        board[7][2] = nullptr;
        board[0][3] = nullptr;
        board[1][3] = nullptr;
        board[2][3] = nullptr;
        board[3][3] = nullptr;
        board[4][3] = nullptr;
        board[5][3] = nullptr;
        board[6][3] = nullptr;
        board[7][3] = nullptr;
        board[0][4] = nullptr;
        board[1][4] = nullptr;
        board[2][4] = nullptr;
        board[3][4] = nullptr;
        board[4][4] = nullptr;
        board[5][4] = nullptr;
        board[6][4] = nullptr;
        board[7][4] = nullptr;
        board[0][5] = nullptr;
        board[1][5] = nullptr;
        board[2][5] = nullptr;
        board[3][5] = nullptr;
        board[4][5] = nullptr;
        board[5][5] = nullptr;
        board[6][5] = nullptr;
        board[7][5] = nullptr;
        board[0][6] = nullptr;
        board[1][6] = nullptr;
        board[2][6] = nullptr;
        board[3][6] = nullptr;
        board[4][6] = nullptr;
        board[5][6] = nullptr;
        board[6][6] = nullptr;
        board[7][6] = nullptr;
        board[0][7] = nullptr;
        board[1][7] = nullptr;
        board[2][7] = nullptr;
        board[3][7] = nullptr;
        board[4][7] = nullptr;
        board[5][7] = nullptr;
        board[6][7] = nullptr;
        board[7][7] = nullptr;
    }
   ~BoardDummy()                                          {                }

   void display(const Position& posHover,
                const Position& posSelect) const          { assert(false); }
   void move       (const Move& move)                     { assert(false); }
   int  getCurrentMove() const                            { assert(false); return 0; }
   bool whiteTurn()      const                            { assert(false); return false; }
   Piece& operator [] (const Position& pos)
   { 
      assert(false); 
      throw true;
   }
   const Piece& operator [] (const Position& pos) const 
   { 
      assert(false); 
      throw true;
   }
};

/***************************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 **************************************************/
class BoardEmpty : public BoardDummy
{
   friend TestBoard;
public:
   Piece * pSpace;

   BoardEmpty();
   ~BoardEmpty();
   const Piece& operator [] (const Position& pos) const
   {
      assert(pos.isValid());
      if (board[pos.getCol()][pos.getRow()])
         return *(board[pos.getCol()][pos.getRow()]);
      else
         return *pSpace;
   }
};

