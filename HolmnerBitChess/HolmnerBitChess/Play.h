#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include <stdio.h>
#include "Global.h"
#include "Init.h"
#include "Search.h"

void playDebugMode(char *FEN);
void play();
static int userSelectSide(int *userSide, int *computerSide, char *customFEN);
static int computerMakesMove(BOARD *board);
static int userMakesMove(BOARD *board);
static void performUserMove(BOARD *board, MOVE_LIST *list, const int moveIndex);
static int getPawnPromotionTypeIndex(MOVE_LIST *list, int piece_type);
static void endMatch(const BOARD *board, const int playingSide);
static int userInputToSquares(char *userInp, int *fromSq, int *toSq);
static int squareStringToSquare_play(const char * squareString);
static void printDebugStuff(BOARD *board);

#endif // PLAY_H_INCLUDED
