/*
CREATED BY JOSEF HOLMNER 2017.
THIS IS A CHESS ENGINE WRITTEN FROM SCRATCH IN C. IT IS FREE TO USE FOR ANYONE.
*/

#include <stdio.h>
#include "Global.h"
#include "Init.h"
#include "Print.h"
#include "Moves.h"
#include "Debug.h"
#include "PerftTest.h"
#include "PerformanceTest.h"
#include "Search.h"
#include "Play.h"


#define RUN_MODE 3 //1:PerftTest //2:PerformanceTest //3:Play // 4:PlayDebugMode //5:TestAndDebug

void testAndDebug(); //only for debugging and testing

int main()
{
	printCurrentBitVersion();			

	switch (RUN_MODE)
	{
	case 1:
		performPerftTest();
		break;
	case 2:
		runPerformanceTest();
		break;
	case 3:
		play();
		break;
	case 4:
		playDebugMode("6k1/5ppp/8/8/8/8/5PPP/6K1 w - - 0 1");
		break;
	case 5:
		testAndDebug();
		break;
	default:
		printf("No known RUN_MODE specified in main()");
		ERROR
	}



	//Exit
	printf("Enter any character to exit\n");
	char bff[8];
	fgets(bff, 6, stdin);

	return 0;
}

void testAndDebug()
{

	BOARD board;
	MOVE bestMove;
	initAll(&board);
//	setUp(&board, "6k1/8/8/8/8/K7/P7/8 b - - 0 1");
	setUp(&board, startFEN);
	printChessBoard(&board);
	MOVE_LIST list;
	getAllConceivableMoves(&board, &list);
	printMoveList(&board, &list);

	//getBestMove_force_depth_dbg(&board, &bestMove, 1);
	getBestMove(&board, &bestMove);
	printMove(&board, &bestMove);
	
}

/*POSSIBLE IMPROVEMENTS*/
//use constant arrays instead of inserting values in the init functions
//use lookup arrays instead of bitshifting MOVE types
//try to not cast to U64 in bitshift MOVE-logic, but use U64 as type input in add
//see if any of the bitboards are unused, delete them in that case
//try to only cast to U64 when shifting > 31 places
//Unmake move faster if in check inside makeMove() functon, no need to do everything and then look for check.
//last elseif statement for all cases in isQueenOrRookAttacked and isQueenOrBistopAttacked, functions could get ~20% faster
//do not insert all values for addMoveToList, for example; enPassSquareNew is not neccecary for non-pawn moves
//speed goal 5 000 000 positions /second 