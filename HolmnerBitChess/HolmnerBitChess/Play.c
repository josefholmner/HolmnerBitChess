#include "Play.h"

//lets user play against computer 
void playDebugMode(char *FEN)
{
	BOARD board;
	MOVE_LIST list;
	int fromSquare, toSquare;
	int keepPlaying = true;

	initAll(&board);
	setUp(&board, FEN);

	char userInput[6] = {0}; //user input

	do
	{
		printDebugStuff(&board);

		if (board.sideToPlay == side_to_play_black)
		{
			printf("\nBlack to play\n");
		}
		else
		{
			printf("\nWhite to play\n");
		}		
		printf("Enter your move: ");
		fgets(userInput, 6, stdin);

		if (userInput[0] == 'q')
		{
			keepPlaying = false;
			continue;
		}

		if (userInputToSquares(userInput, &fromSquare, &toSquare) == false)
		{
			printf("Invalid input!\n");
			continue;
		}
		getAllConceivableMoves(&board, &list);
		int moveIsValid = false;
		int i;
		for (i = 0; i < list.numberOfMoves; i++)
		{
			//Find user input move among all conceivable moves
			if (getFromSquareFromMOVE(list.moves[i].move) == fromSquare
				&& getToSquareFromMOVE(list.moves[i].move) == toSquare)
			{
				if (makeMove(&board, list.moves[i]))
				{
					moveIsValid = true;
				}
				else
				{
					printf("Invalid move; you are in check after that move!\n");
				}
			}
		}
		if (moveIsValid == false)
		{
			printf("Invalid move!\n");
		}
	} while (keepPlaying);
	
}

void play()
{
	BOARD board;	
	int fromSquare, toSquare;
	int userSide;
	int computerSide;
	int stillPlaying = true;
	char customFEN[200];
	char userInput[6] = { 0 }; //user input

	initAll(&board);

	//User selects side
	int customFENentered = userSelectSide(&userSide, &computerSide, customFEN);
	
	//setup board
	if (customFENentered)
	{
		setUp(&board, customFEN);
	}
	else
	{
		setUp(&board, startFEN);
	}

	printChessBoard(&board);
	
	//Main play loop
	while (stillPlaying)
	{
		
		if (board.sideToPlay == userSide)
		{
			if (!userMakesMove(&board))
			{				
				endMatch(&board, userSide);	
				stillPlaying = false; //in case exit is not hit
				break; 
			}
		}
		else // computers turn
		{
			if (!computerMakesMove(&board))
			{
				endMatch(&board, computerSide);
				stillPlaying = false; //in case exit is not hit
				break;
			}
		}

		
	}
	
}

static int userSelectSide(int *userSide, int *computerSide, char *customFEN)
{
	char userInput[6] = { 0 }; //user input
	int validSide = false;
	int customFENentered = false;
	char customSearchDepthDt[10] = { 0 };

	while (!validSide)
	{
		printf("Select side ('w' for white, 'b' for black) [advanced: 'f' for custom start position]: ");
		fgets(userInput, 6, stdin);

		if (userInput[0] == 'b')
		{
			*userSide = side_to_play_black;
			*computerSide = side_to_play_white;
			validSide = true;
		}
		else if (userInput[0] == 'w')
		{
			*userSide = side_to_play_white;
			*computerSide = side_to_play_black;
			validSide = true;
		}
		else if (userInput[0] == 'f')
		{			
			printf("Custom settings; enter start position FEN: ");
			fgets(customFEN, 200, stdin);
			customFENentered = true; 
		}
		else if (userInput[0] == 'd')
		{
			showDebugInfoDurinPlay = !showDebugInfoDurinPlay;
			printf("showDebugInfoDurinPlay: %d\n", showDebugInfoDurinPlay);
		}
		else if (userInput[0] == 't')
		{
			printf("Custom settings; enter serach_depth_delta_time_max (default = 500): ");
			fgets(customSearchDepthDt, 200, stdin);
			search_depth_delta_time_max = atoi(customSearchDepthDt);			
		}
		else if (userInput[0] == 'q')
		{
			exit(0);
		}
		else
		{
			printf("Invalid input! \n");
		}
	}
	return customFENentered;
}

static int computerMakesMove(BOARD *board)
{
	MOVE bestMove;
	MOVE_LIST list;

	//Make sure there are any legal moves
	getAllConceivableMoves(board, &list);
	int i;
	int validMoveCount = 0;
	for (i = 0; i < list.numberOfMoves; i++)
	{
		if (makeMove(board, list.moves[i]))
		{
			validMoveCount++;
			unMakeMove(board, list.moves[i]);
		}
	}
	if (validMoveCount == 0)
	{
		return false;
	}


	getBestMove(board, &bestMove);
	makeMove(board, bestMove);
	printChessBoard(board);
	printf("Computer made move: %s%s\n", getSquareString(getFromSquareFromMOVE(bestMove.move)), getSquareString(getToSquareFromMOVE(bestMove.move)));
	
	return true;
}

static int userMakesMove(BOARD *board)
{
	char userInput[6] = { 0 }; //user input
	int fromSquare, toSquare;
	int validInput = false;
	MOVE_LIST list;

	while (validInput == false)
	{

		//check that there are valid moves
		getAllConceivableMoves(board, &list);
		int i;
		int validMoveCount = 0;
		for (i = 0; i < list.numberOfMoves; i++)
		{
			if (makeMove(board, list.moves[i]))
			{
				validMoveCount++;
				unMakeMove(board, list.moves[i]);
			}
		}
		if (validMoveCount == 0)
		{
			return false;
		}



		if (board->sideToPlay == side_to_play_black)
		{
			printf("Black to play\n");
		}
		else
		{
			printf("White to play\n");
		}
		printf("Enter your move: ");
		fgets(userInput, 6, stdin);

		if (userInput[0] == 'q')
		{
			return false;
		}

		if (userInputToSquares(userInput, &fromSquare, &toSquare) == false)
		{
			printf("Invalid input!\n");
			continue;
		}
		getAllConceivableMoves(board, &list);
		
		
		int moveIsValid = false;
		
		for (i = 0; i < list.numberOfMoves; i++)
		{
			//Find user input move among all conceivable moves
			if (getFromSquareFromMOVE(list.moves[i].move) == fromSquare
				&& getToSquareFromMOVE(list.moves[i].move) == toSquare)
			{
				if (makeMove(board, list.moves[i]))
				{
					moveIsValid = true;
					validInput = true;
					unMakeMove(board, list.moves[i]);
				}
				if (moveIsValid)
				{
					performUserMove(board, &list, i);
					i = list.numberOfMoves; //stop for loop
				}
				else
				{
					printf("Invalid move; you are in check after that move!\n");
				}
			}
		}
		if (moveIsValid == false)
		{
			printf("Invalid move!\n");
		}
	}
	
	printChessBoard(board);
	return true;
}

static void performUserMove(BOARD *board, MOVE_LIST *list, const int moveIndex)
{
	int indexOfMove = moveIndex;
	//check for promoted pawn move (user needs to select what piece type to promote to)
	if (getPawnPromotionTypeFromMOVE(list->moves[moveIndex].move) != no_piece_type)
	{
		int validInput = false;
		char userInput[6] = { 0 }; //user input		

		while (validInput == false)
		{
			printf("Select pawn promotion type ('n' = knight, 'b' = bishop, 'r' = rook, 'q' = queen): ");
			fgets(userInput, 6, stdin);

			switch (userInput[0])
			{
			case 'n':
				indexOfMove = getPawnPromotionTypeIndex(list, bN_type);
				if (indexOfMove == -1)
				{
					indexOfMove = getPawnPromotionTypeIndex(list, wN_type);
				}
				validInput = true;
				break;
			case 'b':
				indexOfMove = getPawnPromotionTypeIndex(list, bB_type);
				if (indexOfMove == -1)
				{
					indexOfMove = getPawnPromotionTypeIndex(list, wB_type);
				}
				validInput = true;
				break;
			case 'r':
				indexOfMove = getPawnPromotionTypeIndex(list, bR_type);
				if (indexOfMove == -1)
				{
					indexOfMove = getPawnPromotionTypeIndex(list, wR_type);
				}
				validInput = true;
				break;
			case 'q':
				indexOfMove = getPawnPromotionTypeIndex(list, bQ_type);
				if (indexOfMove == -1)
				{
					indexOfMove = getPawnPromotionTypeIndex(list, wQ_type);
				}
				validInput = true;
				break;
			default:
				printf("Invalid input!\n");
				break;
			}
		}
	}
	

	makeMove(board, list->moves[indexOfMove]);
}

static int getPawnPromotionTypeIndex(MOVE_LIST *list, int piece_type)
{
	int i;
	for (i = 0; i < list->numberOfMoves; i++)
	{
		if (getPawnPromotionTypeFromMOVE(list->moves[i].move) == piece_type)
		{
			return i;
		}
	}
	return -1;
}

static void endMatch(const BOARD *board, const int playingSide)
{
	if (playingSide == side_to_play_black)
	{
		if (isSquareUnderAttack(board->piecePositions[bK], side_white, board))
		{
			printf("Black is check mate. White wins! \n");
		}
		else
		{
			printf("It's a draw!\n");
		}
	}
	else
	{
		if (isSquareUnderAttack(board->piecePositions[wK], side_black, board))
		{
			printf("White is check mate. Black wins! \n");
		}
		else
		{
			printf("It's a draw!\n");
		}
	}
	
	//Exit
	printf("\n\nEnter any character to exit\n");
	char bff[8];
	fgets(bff, 6, stdin);
	exit(0);
}

static int userInputToSquares(char *userInp, int *fromSq, int *toSq)
{
	*fromSq = squareStringToSquare_play(&userInp[0]);
	*toSq = squareStringToSquare_play(&userInp[2]);

	if (*fromSq == -1 || *toSq == -1)
	{
		return false;
	}

	return true;
}

static int squareStringToSquare_play(const char * squareString)
{
	int ascii_0 = 48;
	int ascii_a = 97;

	if (squareString[0] - ascii_a < 0 || squareString[0] - ascii_a > 7 || squareString[1] - ascii_0 < 1 || squareString[1] - ascii_0 > 8)
	{
		return -1;
	}
	return ((squareString[0] - ascii_a)) + abs((squareString[1] - ascii_0) * 8 - NUMBER_OF_SQUARES);
}

static void printDebugStuff(BOARD *board)
{
	printChessBoard_dbg(board);
}

