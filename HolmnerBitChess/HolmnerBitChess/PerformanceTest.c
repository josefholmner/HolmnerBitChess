#include "PerformanceTest.h"

int lastDepthPerftCount;

void runPerformanceTest()
{
	BOARD board;
	initAll(&board);
	setUp(&board, startFEN);
	printf("This could take up to a minute to complete...\n");
	clock_t start = clock(), diff;

	lastDepthPerftCount = 0;
	int score = negaMaxSearch_performanceTest(&board, 5);

	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Performance test time: %d msec, moves explored at last level: %d\n", msec, lastDepthPerftCount);
}

static int negaMaxSearch_performanceTest(BOARD *board, const int depth)
{
	if (depth <= 0)
	{
#ifdef _DEBUG
		int scr = evaluateBoard_public(board);
		ASSERT(scr > -1000000 && scr < 1000000)
#endif // _DEBUG
			return evaluateBoard_public(board);
	}
	int bestMoveScore = -100000;
	int score;

	MOVE_LIST movelist;
	getAllConceivableMoves(board, &movelist);

	int i;
	for (i = 0; i < movelist.numberOfMoves; i++)
	{
		setNextMove_public(i, &movelist);
		if (makeMove(board, movelist.moves[i]))
		{
			if (depth == 1)
			{
				lastDepthPerftCount++;
			}
			score = -negaMaxSearch_performanceTest(board, depth - 1);
			if (score > bestMoveScore)
			{
				bestMoveScore = score;
			}
			unMakeMove(board, movelist.moves[i]);
		}
	}

	return bestMoveScore;
}