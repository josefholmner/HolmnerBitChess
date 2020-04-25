#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <time.h>
#include "Global.h"
#include "Debug.h"
#include "Moves.h"
#include "PiecesAndSquares.h"

void getBestMove(BOARD *board, MOVE *bestMove);
void getBestMove_force_depth_dbg(BOARD *board, MOVE *bestMove, int depth);
static int alphaBeta(BOARD *board, int depth, int alpha, int beta);
static int alphaBeta_getBest(BOARD *board, int depth, int alpha, int beta, MOVE *bestMove);
int evalQuiet(BOARD *board, int alpha, int beta);
void setNextMove_public(const int currentSearchIndex, MOVE_LIST *list);
void setNextMove(const int currentSearchIndex, MOVE_LIST *list);
int evaluateBoard_public(const BOARD *board);
static int evaluateBoard(const BOARD *board);
int getConnectedRooksScore_public(const BOARD *board, const int rook1, const int rook2);
static int getConnectedRooksScore(const BOARD *board, const int rook1, const int rook2);
static int getRookOpenFileScore(const BOARD *board, const int square, const int side);
static int minorPiecePawnProtectedScore(const BOARD *board, const int square, const int side);
static int doublePawnsPenaltyScore(const BOARD *board, const int side);
static int getKingSafetyScore(const BOARD *board, const int side);
static int trappedRookPenaltyScore(const BOARD *board, const int square, const int side);
#endif