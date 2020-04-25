#ifndef PERFTTEST_H_INCLUDED
#define PERFTTEST_H_INCLUDED

#include <stdio.h>
#include "Global.h"
#include "Init.h"
#include "Print.h"
#include "Moves.h"
#include "Debug.h"
#include "PerftTest.h"
#include "Search.h"

void performPerftTest();
static int negaMaxSearch_perft(BOARD *board, const int depth);
static void getFENfromPerft(const char perftLine[], char FEN[]);
static void getDepthMoveCountfromPerft(const char perftLine[], const int depth, int *moveCount);

#endif