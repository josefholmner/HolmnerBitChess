#include "Search.h"

int visitedNodesCount;

const U64 squareToFile[NUMBER_OF_SQUARES] = {
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H, 
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H,
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H,
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H,
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H,
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H,
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H,
	file_A, file_B, file_C, file_D, file_E, file_F, file_G, file_H
};

const int squareToFileIndex[NUMBER_OF_SQUARES] = {
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7,
	0,	1,	2,	3,	4,	5,	6,	7
};

const int squareToRankIndex[NUMBER_OF_SQUARES] = {
	7,	7,	7,	7,	7,	7,	7,	7,
	6,	6,	6,	6,	6,	6,	6,	6,
	5,	5,	5,	5,	5,	5,	5,	5,
	4,	4,	4,	4,	4,	4,	4,	4,
	3,	3,	3,	3,	3,	3,	3,	3,
	2,	2,	2,	2,	2,	2,	2,	2,
	1,	1,	1,	1,	1,	1,	1,	1,
	0,	0,	0,	0,	0,	0,	0,	0
};

const int black_pawn_scores[64] = {
	1000	,	1000	,	1000	,	1000	,	1000	,	1000	,	1000	,	1000	,
	1000	,	1100	,	1100	,	1100	,	1100	,	1100	,	1100	,	1000	,
	1000	,	1100	,	1200	,	1200	,	1200	,	1200	,	1100	,	1000	,
	1000	,	1100	,	1200	,	1400	,	1400	,	1200	,	1100	,	1000	,
	1000	,	1100	,	1200	,	1400	,	1400	,	1200	,	1100	,	1000	,
	1000	,	1200	,	1400	,	1600	,	1600	,	1400	,	1200	,	1000	,
	1800	,	1800	,	1800	,	2000	,	2000	,	1800	,	1800	,	1800	,
	1800	,	1800	,	1800	,	2000	,	2000	,	1800	,	1800	,	1800	
};

const int white_pawn_scores[64] = {
	1800	,	1800	,	1800	,	2000	,	2000	,	1800	,	1800	,	1800	,
	1800	,	1800	,	1800	,	2000	,	2000	,	1800	,	1800	,	1800	,
	1000	,	1200	,	1400	,	1600	,	1600	,	1400	,	1200	,	1000	,
	1000	,	1100	,	1200	,	1400	,	1400	,	1200	,	1100	,	1000	,
	1000	,	1100	,	1200	,	1400	,	1400	,	1200	,	1100	,	1000	,
	1000	,	1100	,	1200	,	1200	,	1200	,	1200	,	1100	,	1000	,
	1000	,	1100	,	1100	,	1100	,	1100	,	1100	,	1100	,	1000	,
	1000	,	1000	,	1000	,	1000	,	1000	,	1000	,	1000	,	1000	
};

const int black_knight_scores[64] = {
	3000	,	2700	,	3000	,	3000	,	3000	,	3000	,	2700	,	3000	,
	3000	,	3100	,	3100	,	3100	,	3100	,	3100	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3200	,	3200	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3400	,	3400	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3400	,	3400	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3200	,	3200	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3100	,	3100	,	3100	,	3100	,	3100	,	3000	,
	3000	,	3000	,	3000	,	3000	,	3000	,	3000	,	3000	,	3000	
};

const int white_knight_scores[64] = {
	3000	,	3000	,	3000	,	3000	,	3000	,	3000	,	3000	,	3000	,
	3000	,	3100	,	3100	,	3100	,	3100	,	3100	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3200	,	3200	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3400	,	3400	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3400	,	3400	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3200	,	3200	,	3200	,	3200	,	3100	,	3000	,
	3000	,	3100	,	3100	,	3100	,	3100	,	3100	,	3100	,	3000	,
	3000	,	2700	,	3000	,	3000	,	3000	,	3000	,	2700	,	3000
};

const int black_bishop_scores[64] = {
	3050	,	3050	,	2750	,	3050	,	3000	,	2750	,	3050	,	3050	,
	3050	,	3150	,	3150	,	3150	,	3150	,	3150	,	3150	,	3050	,
	3050	,	3250	,	3250	,	3250	,	3250	,	3250	,	3250	,	3050	,
	3050	,	3250	,	3350	,	3450	,	3450	,	3350	,	3250	,	3050	,
	3050	,	3250	,	3350	,	3450	,	3450	,	3350	,	3250	,	3050	,
	3050	,	3250	,	3250	,	3250	,	3250	,	3250	,	3250	,	3050	,
	3050	,	3150	,	3150	,	3150	,	3150	,	3150	,	3150	,	3050	,
	3050	,	3050	,	3050	,	3050	,	3050	,	3050	,	3050	,	3050
};

const int white_bishop_scores[64] = {
	3050	,	3050	,	3050	,	3050	,	3050	,	3050	,	3050	,	3050	,
	3050	,	3150	,	3150	,	3150	,	3150	,	3150	,	3150	,	3050	,
	3050	,	3250	,	3250	,	3250	,	3250	,	3250	,	3250	,	3050	,
	3050	,	3250	,	3350	,	3450	,	3450	,	3350	,	3250	,	3050	,
	3050	,	3250	,	3350	,	3450	,	3450	,	3350	,	3250	,	3050	,
	3050	,	3250	,	3250	,	3250	,	3250	,	3250	,	3250	,	3050	,
	3050	,	3150	,	3150	,	3150	,	3150	,	3150	,	3150	,	3050	,
	3050	,	3050	,	2750	,	3050	,	3050	,	2750	,	3050	,	3050
};

const int rook_scores[64] = {
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	,
	5000	,	5075	,	5150	,	5225	,	5225	,	5150	,	5075	,	5000	
};

const int white_king_scores[64] = {
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100500	,	100500	,	100400	,	100000	,	100000	,	100000	,	100500	,	100500
};

const int black_king_scores[64] = {
	100500	,	100500	,	100400	,	100000	,	100000	,	100000	,	100500	,	100500	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,
	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000	,	100000
};


void getBestMove(BOARD *board, MOVE *bestMove)
{
	visitedNodesCount = 0;
	MOVE winning_or_loosing_move;
	int deltaTime = 0;
	int depth = 0;
	int score = -10000000;

	while (deltaTime < search_depth_delta_time_max)
	{
		depth += 2;

		clock_t start = clock(), diff;

		score = alphaBeta_getBest(board, depth, -1000000, 1000000, bestMove);

		diff = clock() - start;
		deltaTime = diff * 1000 / CLOCKS_PER_SEC;				
	}

	if (score > 100000) //we have found a winning move
	{
		//try to find the quickest win
		int depth_shallower = depth;
		while (depth_shallower > 0)
		{
			depth_shallower -= 2;
			int score_shallower = alphaBeta_getBest(board, depth_shallower, -1000000, 1000000, &winning_or_loosing_move);
			if (score_shallower > 100000)
			{
				*bestMove = winning_or_loosing_move;
			}
		}
	}

	if (score < -100000) //we have found a loosing move
	{
		//try to find the slowest loss
		int depth_shallower = depth;
		int stop = false;
		while (depth_shallower > 0 && !stop)
		{
			depth_shallower -= 2;
			int score_shallower = alphaBeta_getBest(board, depth_shallower, -1000000, 1000000, &winning_or_loosing_move);
			if (score_shallower > -100000)
			{
				*bestMove = winning_or_loosing_move;
				stop = true;
			}
		}
	}
	if (showDebugInfoDurinPlay)
	{
		printf("depth: %d\t time: %d\t score: %d\t nodes visited: %d\n", depth, deltaTime, score, visitedNodesCount);
	}	
}

void getBestMove_force_depth_dbg(BOARD *board, MOVE *bestMove, int depth)
{
	visitedNodesCount = 0;
	MOVE winning_or_loosing_move;
	int deltaTime = 0;
	int score = -10000000;


	clock_t start = clock(), diff;

	score = alphaBeta_getBest(board, depth, -1000000, 1000000, bestMove);

	diff = clock() - start;
	deltaTime = diff * 1000 / CLOCKS_PER_SEC;
	


	printf("depth: %d\t time: %d\t score: %d\t nodes visited: %d\n", depth, deltaTime, score, visitedNodesCount);
}


static int alphaBeta(BOARD *board, int depth, int alpha, int beta)
{
	if (depth <= 0)
	{
		//return evaluateBoard(board);
		return evalQuiet(board, alpha, beta);
	}
	int score;

	MOVE_LIST movelist;
	getAllConceivableMoves(board, &movelist);

	int i;
	for (i = 0; i < movelist.numberOfMoves; i++)
	{
		setNextMove(i, &movelist);

		if (makeMove(board, movelist.moves[i]))
		{
			visitedNodesCount++;

			score = -alphaBeta(board, depth - 1, -beta, -alpha);
			unMakeMove(board, movelist.moves[i]);
			if (score >= beta)
			{
				return beta;  //prune cutoff
			}				
			if (score > alpha)
			{
				alpha = score;
			}				
			
		}
	}

	return alpha;
}


static int alphaBeta_getBest(BOARD *board, int depth, int alpha, int beta, MOVE *bestMove)
{

	int score;
	int bestScore = -10000000;

	MOVE_LIST movelist;
	getAllConceivableMoves(board, &movelist);
	
	int i;
	for (i = 0; i < movelist.numberOfMoves; i++)
	{
		setNextMove(i, &movelist);

		if (makeMove(board, movelist.moves[i]))
		{
			visitedNodesCount++;

			score = -alphaBeta(board, depth - 1, -beta, -alpha);
			unMakeMove(board, movelist.moves[i]);

			if (score > bestScore)
			{
				bestScore = score;
				*bestMove = movelist.moves[i];
			}

			if (score > alpha)
			{
				alpha = score;
			}

		}
	}

	return bestScore;
}


int evalQuiet(BOARD *board, int alpha, int beta) 
{
	int stand_pat = evaluateBoard(board);
	if (stand_pat >= beta)
	{
		return beta;
	}
		
	if (alpha < stand_pat)
	{
		alpha = stand_pat;
	}		

	int score;

	MOVE_LIST movelist;
	getAllConceivableMoves(board, &movelist);

	int i;
	for (i = 0; i < movelist.numberOfMoves; i++)
	{
		setNextMove(i, &movelist);



		if(getCapturedPieceFromMOVE(movelist.moves[i].move) == no_piece) //only evaluate capture moves
		{
			i = movelist.numberOfMoves;
			continue;
		}
		else
		{
			if (makeMove(board, movelist.moves[i]))
			{
				visitedNodesCount++;

				score = -evalQuiet(board, -beta, -alpha);
				unMakeMove(board, movelist.moves[i]);


				if (score >= beta)
				{
					return beta;
				}
					
				if (score > alpha)
				{
					alpha = score;
				}					
							
			}
		}		
	}
	return alpha;
}

void setNextMove_public(const int currentSearchIndex, MOVE_LIST *list)
{
	setNextMove(currentSearchIndex, list);
}

void setNextMove(const int currentSearchIndex, MOVE_LIST *list)
{
	int i;
	int bestScoreIndex = currentSearchIndex;
	int bestScore = -1000000000;

	for (i = currentSearchIndex; i < list->numberOfMoves; i++)
	{
#ifdef _DEBUG
		ASSERT(list->moves[i].score >= -8 && list->moves[i].score < 131)
#endif 

		if (list->moves[i].score > bestScore)
		{
			bestScore = list->moves[i].score;
			bestScoreIndex = i;
		}
	}

	MOVE move_tmp = list->moves[currentSearchIndex];
	list->moves[currentSearchIndex] = list->moves[bestScoreIndex];
	list->moves[bestScoreIndex] = move_tmp;
}

//used in debugging and testing
int evaluateBoard_public(const BOARD *board)
{
	return evaluateBoard(board);
}

static int evaluateBoard(const BOARD *board)
{
	int piece;
	int score = 0;
	for (piece = FIRST_PIECE_BLACK; piece <= LAST_PIECE_WHITE; piece++)
	{
		//only evaluate on board pieces
		if (board->piecePositions[piece] == no_square)
		{
			continue;
		}
		
		switch (board->pieceTypes[piece])
		{
		case bP_type:
			score -= black_pawn_scores[board->piecePositions[piece]];
			break;
		case bR_type:
			score -= rook_scores[board->piecePositions[piece]];
			score -= getRookOpenFileScore(board, board->piecePositions[piece], side_black);
			score -= trappedRookPenaltyScore(board, board->piecePositions[piece], side_black);
			break;
		case bN_type:
			score -= black_knight_scores[board->piecePositions[piece]];
			score -= minorPiecePawnProtectedScore(board, board->piecePositions[piece], side_black);
			break;
		case bB_type:
			score -= black_bishop_scores[board->piecePositions[piece]];
			score -= minorPiecePawnProtectedScore(board, board->piecePositions[piece], side_black);
			break;
		case bQ_type:
			score -= 9000;
			break;
		case bK_type:
			score -= black_king_scores[board->piecePositions[piece]];
			break;

		case wP_type:
			score += white_pawn_scores[board->piecePositions[piece]];
			break;
		case wR_type:			
			score += rook_scores[board->piecePositions[piece]];
			score += getRookOpenFileScore(board, board->piecePositions[piece], side_white);
			score += trappedRookPenaltyScore(board, board->piecePositions[piece], side_white);
			break;
		case wN_type:
			score += white_knight_scores[board->piecePositions[piece]];
			score += minorPiecePawnProtectedScore(board, board->piecePositions[piece], side_white);
			break;
		case wB_type:
			score += white_bishop_scores[board->piecePositions[piece]];
			score += minorPiecePawnProtectedScore(board, board->piecePositions[piece], side_white);
			break;
		case wQ_type:
			score += 9000;
			break;
		case wK_type:
			score += white_king_scores[board->piecePositions[piece]];
			break;
		case no_piece_type:
			break;
		default:
			printf("ERROR: unknown piece type: %d", board->pieceTypes[piece]);
			ERROR
		}
	}

	//check rook connected
	score += getConnectedRooksScore(board, wR1, wR2);
	score -= getConnectedRooksScore(board, bR1, bR2);
	//check double pawns
	score += doublePawnsPenaltyScore(board, side_white);
	score -= doublePawnsPenaltyScore(board, side_black);
	//check king safety
	score += getKingSafetyScore(board, side_white);
	score -= getKingSafetyScore(board, side_black);

	//return score;
	if (board->sideToPlay == side_to_play_black)
	{
		return -score; //so that negaMax style recursive search will be valid
	}
	else
	{
		return score;
	}	
}

int getConnectedRooksScore_public(const BOARD *board, const int rook1, const int rook2)
{
	return getConnectedRooksScore(board, rook1, rook2);
}

static int getConnectedRooksScore(const BOARD *board, const int rook1, const int rook2)
{
	int rook1_position = board->piecePositions[rook1];
	int rook2_position = board->piecePositions[rook2];

	if (rook1_position == no_square || rook2_position == no_square)
	{
		return 0;
	}
	
	int file_rook1 = squareToFileIndex[rook1_position];
	int file_rook2 = squareToFileIndex[rook2_position];
	int rank_rook1 = squareToRankIndex[rook1_position];
	int rank_rook2 = squareToRankIndex[rook2_position];

	if (rank_rook1 == rank_rook2)
	{
		int leftMostPosition;
		int rightMostPosition;

		if (file_rook1 < file_rook2)
		{
			leftMostPosition = rook1_position;
			rightMostPosition = rook2_position;
		}
		else
		{
			leftMostPosition = rook2_position;
			rightMostPosition = rook1_position;
		}
		leftMostPosition++;
		//scan each square between rooks
		while (leftMostPosition < rightMostPosition)
		{
			if (board->chessBoard[leftMostPosition] != no_piece)
			{
				return 0;
			}
			leftMostPosition++;
		}
	}
	else if (file_rook1 == file_rook2)
	{
		int bottomMostPosition;
		int topMostPosition;

		if (rank_rook1 < rank_rook2)
		{
			bottomMostPosition = rook1_position;
			topMostPosition = rook2_position;
		}
		else
		{
			bottomMostPosition = rook2_position;
			topMostPosition = rook1_position;
		}
		bottomMostPosition -= 8; //square matrix actually starts in top left corner and ends in bottom right
		//scan each square between rooks
		while (bottomMostPosition > topMostPosition)
		{
			if (board->chessBoard[bottomMostPosition] != no_piece)
			{
				return 0;
			}
			bottomMostPosition -= 8;
		}
	}
	else
	{
		return 0;
	}


	return 300;
}

static int getRookOpenFileScore(const BOARD *board, const int square, const int side)
{
	U64 rookFile = squareToFile[square];

	if (side == side_black)
	{
		if (!(rookFile & board->bitBoards[bP_type]))
		{
			return 400;
		}
	}
	else //side: white
	{
		if (!(rookFile & board->bitBoards[wP_type]))
		{
			return 400;
		}
	}

	return 0;
}

static int trappedRookPenaltyScore(const BOARD *board, const int square, const int side)
{
	
	if (side == side_black)
	{
		switch (square)
		{
		case H8:
			if (board->bitBoards[bK_type] & (bitSquares[F8] | bitSquares[G8]))
			{
				return -800;
			}
			break;
		case G8:
			if (board->bitBoards[bK_type] & (bitSquares[F8]))
			{
				return -800;
			}
			break;
		case A8:
			if (board->bitBoards[bK_type] & (bitSquares[B8] | bitSquares[C8]))
			{
				return -800;
			}
			break;
		case B8:
			if (board->bitBoards[bK_type] & (bitSquares[C8]))
			{
				return -800;
			}
			break;
		default:
			break;
		}
	}
	else //side: white
	{
		switch (square)
		{
			case H1:
				if (board->bitBoards[wK_type] & (bitSquares[F1] | bitSquares[G1]))
				{
					return -800;
				}
				break;
			case G1:
				if (board->bitBoards[wK_type] & (bitSquares[F1]))
				{
					return -800;
				}
				break;
			case A1:
				if (board->bitBoards[wK_type] & (bitSquares[B1] | bitSquares[C1]))
				{
					return -800;
				}
				break;
			case B1:
				if (board->bitBoards[wK_type] & (bitSquares[C1]))
				{
					return -800;
				}
				break;
		default:
			break;
		}		
	}

	return 0;
}

static int minorPiecePawnProtectedScore(const BOARD *board, const int square, const int side)
{	
	if (side == side_black)
	{
		if (board->bitBoards[bP_type] & getBlackPawnAttackPatternBits(square))
		{
			return 100;
		}
	}
	else
	{
		if (board->bitBoards[wP_type] & getWhitePawnAttackPatternBits(square))
		{
			return 100;
		}
	}

	return 0;
}

static int doublePawnsPenaltyScore(const BOARD *board, const int side)
{
	int score = 0;
	int filePawnCount[8] = { 0 };
		
	if (side == side_black)
	{
		int pawn;
		for (pawn = bP1; pawn <= bP8; pawn++)
		{			
			if (board->piecePositions[pawn] != no_square && board->pieceTypes[pawn] == bP_type)
			{
				//sum all file pawn counts
				filePawnCount[squareToFileIndex[board->piecePositions[pawn]]]++;
			}
		}		
	}
	else
	{
		int pawn;
		for (pawn = wP1; pawn <= wP8; pawn++)
		{
			if (board->piecePositions[pawn] != no_square && board->pieceTypes[pawn] == wP_type)
			{
				//sum all file pawn counts
				filePawnCount[squareToFileIndex[board->piecePositions[pawn]]]++;
			}
		}
	}

	int i;
	for (i = 0; i < 8; i++)
	{
		if (filePawnCount[i] > 1)
		{
			score -= (filePawnCount[i] * 250 - 250);
		}
	}

	return score;
}

static int getKingSafetyScore(const BOARD *board, const int side)
{
	int score = 0;

	if (side == side_black)
	{
		if (board->bitBoards[bK_type] & (bitSquares[G8] | bitSquares[H8] | bitSquares[H7] | bitSquares[G7]))
		{
			if (board->chessBoard[F7] != no_piece && board->pieceTypes[board->chessBoard[F7]] == bP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[F6] != no_piece && board->pieceTypes[board->chessBoard[F6]] == bP_type)
			{
				score += 100;
			}

			if (board->chessBoard[G7] != no_piece && board->pieceTypes[board->chessBoard[G7]] == bP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[G6] != no_piece && board->pieceTypes[board->chessBoard[G6]] == bP_type)
			{
				score += 100;
			}

			if (board->chessBoard[H7] != no_piece && board->pieceTypes[board->chessBoard[H7]] == bP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[H6] != no_piece && board->pieceTypes[board->chessBoard[H6]] == bP_type)
			{
				score += 100;
			}
		}
		else if (board->bitBoards[bK_type] & (bitSquares[A8] | bitSquares[B8] | bitSquares[C8] | bitSquares[A7] | bitSquares[B7] | bitSquares[C7]))
		{
			if (board->chessBoard[A7] != no_piece && board->pieceTypes[board->chessBoard[A7]] == bP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[A6] != no_piece && board->pieceTypes[board->chessBoard[A6]] == bP_type)
			{
				score += 100;
			}

			if (board->chessBoard[B7] != no_piece && board->pieceTypes[board->chessBoard[B7]] == bP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[B6] != no_piece && board->pieceTypes[board->chessBoard[B6]] == bP_type)
			{
				score += 100;
			}

			if (board->chessBoard[C7] != no_piece && board->pieceTypes[board->chessBoard[C7]] == bP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[C6] != no_piece && board->pieceTypes[board->chessBoard[C6]] == bP_type)
			{
				score += 100;
			}
		}
	}
	else //side: white
	{
		if (board->bitBoards[wK_type] & (bitSquares[G1] | bitSquares[H1] | bitSquares[G2] | bitSquares[H2]))
		{
			if (board->chessBoard[F2] != no_piece && board->pieceTypes[board->chessBoard[F2]] == wP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[F3] != no_piece && board->pieceTypes[board->chessBoard[F3]] == wP_type)
			{
				score += 100;
			}

			if (board->chessBoard[G2] != no_piece && board->pieceTypes[board->chessBoard[G2]] == wP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[G3] != no_piece && board->pieceTypes[board->chessBoard[G3]] == wP_type)
			{
				score += 100;
			}

			if (board->chessBoard[H2] != no_piece && board->pieceTypes[board->chessBoard[H2]] == wP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[H3] != no_piece && board->pieceTypes[board->chessBoard[H3]] == wP_type)
			{
				score += 100;
			}
		}
		else if (board->bitBoards[wK_type] & (bitSquares[A1] | bitSquares[B1] | bitSquares[C1] | bitSquares[A2] | bitSquares[B2] | bitSquares[C2]))
		{
			if (board->chessBoard[A2] != no_piece && board->pieceTypes[board->chessBoard[A2]] == wP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[A3] != no_piece && board->pieceTypes[board->chessBoard[A3]] == wP_type)
			{
				score += 100;
			}

			if (board->chessBoard[B2] != no_piece && board->pieceTypes[board->chessBoard[B2]] == wP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[B3] != no_piece && board->pieceTypes[board->chessBoard[B3]] == wP_type)
			{
				score += 100;
			}

			if (board->chessBoard[C2] != no_piece && board->pieceTypes[board->chessBoard[C2]] == wP_type)
			{
				score += 200;
			}
			else if (board->chessBoard[C3] != no_piece && board->pieceTypes[board->chessBoard[C3]] == wP_type)
			{
				score += 100;
			}
		}
	}

	return score;
}