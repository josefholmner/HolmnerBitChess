#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include "Global.h"
#include "PiecesAndSquares.h"
#include "Error.h"
#include "Debug.h"
#include "Moves.h"

//Used to not get stuck in infinite when parsing FEN
#define MAX_FEN_CHARS 1000

//Piece catagory
enum
{
	rook_knight_bishop_cat, queen_cat, king_cat, pawn_cat
};


void initAll(BOARD *board);
void setUp(BOARD *board, const char FEN[]);
static int insertPiecesFromFEN(BOARD *board, const char FEN[]);
static void insertPieceFromFEN(BOARD *board, const int piece, const int pieceType, const int pieceCatagory, const int firstPawn, const int square);
static int insertSideToPlayFromFEN(BOARD* board, const char FEN[], const int index);
static int insertCastlePermsFromFEN(BOARD* board, const char FEN[], const int index);
static int insertEnPassantSquareFromFEN(BOARD* board, const char FEN[], const int index);
static int insertHalfMovesFromFEN(BOARD* board, const char FEN[], const int index);
static void updateBitBoardFromInsertedPiece(BOARD *board, const int piece, const int squareTo);
static void ensureValidBitboards(BOARD *board);
#endif 
