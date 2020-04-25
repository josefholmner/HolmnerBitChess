#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "PiecesAndSquares.h"
#include "Error.h"
#include "Global.h"
#include "Moves.h"


void printCurrentBitVersion();
void printBitBoard(const U64 bits);
void printChessBoard_dbg(const BOARD *board);
void printU64asBits(const U64 bits);
void printChessBoard(const BOARD *board);
void printMove(const BOARD *board, const MOVE *move);
void printMoveList(const BOARD *board, const MOVE_LIST *list);
void printBoard_all(const BOARD *board);
void printBits_4(const int bits);
char * getChessPieceString(const int chessPiece);
char * getChessPieceTypeString(const int pieceType);
char * getSquareString(const int square);

#endif 
