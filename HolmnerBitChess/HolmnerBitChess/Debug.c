#include "Debug.h"

int isBoardEqual(const BOARD *board1, const BOARD *board2)
{
	int i;
	for (i = 0; i < NUMBER_OF_SQUARES; i++)
	{
		if (!(board1->chessBoard[i] == board2->chessBoard[i]))
		{
			return false;
		}
	}

	for (i = 0; i < NUMBER_OF_PIECES + 1; i++)
	{
		if (!(board1->piecePositions[i] == board2->piecePositions[i]))
		{
			return false;
		}
	}
	
	if(!(board1->sideToPlay == board2->sideToPlay))
	{
		return false;
	}

	if(!(board1->castlePerm == board2->castlePerm))
	{
		return false;
	}

	if(!(board1->enPassantSquare == board2->enPassantSquare))
	{
		return false;
	}

	if(!(board1->halfMoves == board2->halfMoves))
	{
		return false;
	}

	for (i = 0; i < NUMBER_OF_BIT_BOARDS; i++)
	{
		if(!(board1->bitBoards[i] == board2->bitBoards[i]))
		{
			return false;
		}
	}
	for (i = 0; i < NUMBER_OF_PIECES + 1; i++)
	{
		if(!(board1->pieceTypes[i] == board2->pieceTypes[i]))
		{
			return false;
		}
	}

	return true;
}