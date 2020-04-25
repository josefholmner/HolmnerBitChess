#ifndef PERFORMANCETEST_H_INCLUDED
#define PERFORMANCETEST_H_INCLUDED

#include <stdio.h>
#include "Global.h"
#include "Init.h"
#include "Moves.h"
#include "Debug.h"
#include <time.h>
#include "Search.h"

void runPerformanceTest();
static int negaMaxSearch_performanceTest(BOARD *board, const int depth);

#endif