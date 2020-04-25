#include "Init.h"


void initAll(BOARD *board)
{	
	int i;
	for (i = 0; i < NUMBER_OF_BIT_BOARDS; i++)
	{
		board->bitBoards[i] = EMPTY_BIT_BOARD;
	}

	board->sideToPlay = side_to_play_undefined;

	//Chessboard	
	for (i = 0; i < NUMBER_OF_SQUARES; i++)
	{
		board->chessBoard[i] = no_piece;
	}

	//Piece positions
	for (i = 0; i < NUMBER_OF_PIECES; i++)
	{
		board->piecePositions[i] = no_square;
	}
	
	//Piece types
	for (i = 0; i < NUMBER_OF_PIECES + 1; i++) //last index hold no_piece piecetype
	{
		board->pieceTypes[i] = no_piece_type;
	}

	//bitSquares
	for (i = 0; i < NUMBER_OF_SQUARES; i++)
	{
		bitSquares[i] = 1ULL << i;
	}

	//castlePermissions
	board->castlePerm = castle_null;

	//En passant square
	board->enPassantSquare = no_square;

	//Half moves
	board->halfMoves = 0;

	//isPawn
	for (i = 0; i < NUMBER_OF_PIECES; i++)
	{
		switch (i)
		{
		case bP1:
		case bP2:
		case bP3:
		case bP4:
		case bP5:
		case bP6:
		case bP7:
		case bP8:
			isPawn[i] = true;
			break;
		case bR1:
		case bR2:
		case bN1:
		case bN2:
		case bB1:
		case bB2:
		case bQ:
		case bK:
			isPawn[i] = false;
			break;
		case wP1:
		case wP2:
		case wP3:
		case wP4:
		case wP5:
		case wP6:
		case wP7:
		case wP8:
			isPawn[i] = true;
			break;
		case wR1:
		case wR2:
		case wN1:
		case wN2:
		case wB1:
		case wB2:
		case wQ:
		case wK:
			isPawn[i] = false;
			break;
		default:
			printf("Unknown piece type: %d\n", i);
			ERROR
		}
	}

	//colourOfPiece
	for (i = 0; i < NUMBER_OF_PIECES; i++)
	{
		switch (i)
		{
		case bP1:
		case bP2:
		case bP3:
		case bP4:
		case bP5:
		case bP6:
		case bP7:
		case bP8:			
		case bR1:
		case bR2:
		case bN1:
		case bN2:
		case bB1:
		case bB2:
		case bQ:
		case bK:
			colourOfPiece[i] = black_colour;
			break;
		case wP1:
		case wP2:
		case wP3:
		case wP4:
		case wP5:
		case wP6:
		case wP7:
		case wP8:
		case wR1:
		case wR2:
		case wN1:
		case wN2:
		case wB1:
		case wB2:
		case wQ:
		case wK:
			colourOfPiece[i] = white_colour;
			break;
		default:
			printf("Unknown piece type: %d\n", i);
			ERROR
		}
	}

	int j;
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 10; j++)
		{
			//Init all scores to -1 (not all will be assigned a value after)
			capture_score[i][j] = -1;
		}
	}

	capture_score[wP_type][bQ_type] = 100 + 9 - 1;
	capture_score[wN_type][bQ_type] = 100 + 9 - 3;
	capture_score[wB_type][bQ_type] = 100 + 9 - 3;
	capture_score[wR_type][bQ_type] = 100 + 9 - 5;
	capture_score[wQ_type][bQ_type] = 100 + 9 - 9;
	capture_score[wK_type][bQ_type] = 100 + 9 - 10;

	capture_score[wP_type][bR_type] = 100 + 5 - 1;
	capture_score[wN_type][bR_type] = 100 + 5 - 3;
	capture_score[wB_type][bR_type] = 100 + 5 - 3;
	capture_score[wR_type][bR_type] = 100 + 5 - 5;
	capture_score[wQ_type][bR_type] = 100 + 5 - 9;
	capture_score[wK_type][bR_type] = 100 + 5 - 10;

	capture_score[wP_type][bB_type] = 100 + 3 - 1;
	capture_score[wN_type][bB_type] = 100 + 3 - 3;
	capture_score[wB_type][bB_type] = 100 + 3 - 3;
	capture_score[wR_type][bB_type] = 100 + 3 - 5;
	capture_score[wQ_type][bB_type] = 100 + 3 - 9;
	capture_score[wK_type][bB_type] = 100 + 3 - 10;

	capture_score[wP_type][bN_type] = 100 + 3 - 1;
	capture_score[wN_type][bN_type] = 100 + 3 - 3;
	capture_score[wB_type][bN_type] = 100 + 3 - 3;
	capture_score[wR_type][bN_type] = 100 + 3 - 5;
	capture_score[wQ_type][bN_type] = 100 + 3 - 9;
	capture_score[wK_type][bN_type] = 100 + 3 - 10;

	capture_score[wP_type][bP_type] = 100 + 1 - 1;
	capture_score[wN_type][bP_type] = 100 + 1 - 3;
	capture_score[wB_type][bP_type] = 100 + 1 - 3;
	capture_score[wR_type][bP_type] = 100 + 1 - 5;
	capture_score[wQ_type][bP_type] = 100 + 1 - 9;
	capture_score[wK_type][bP_type] = 100 + 1 - 10;

	capture_score[bP_type][wQ_type] = 100 + 9 - 1;
	capture_score[bN_type][wQ_type] = 100 + 9 - 3;
	capture_score[bB_type][wQ_type] = 100 + 9 - 3;
	capture_score[bR_type][wQ_type] = 100 + 9 - 5;
	capture_score[bQ_type][wQ_type] = 100 + 9 - 9;
	capture_score[bK_type][wQ_type] = 100 + 9 - 10;

	capture_score[bP_type][wR_type] = 100 + 5 - 1;
	capture_score[bN_type][wR_type] = 100 + 5 - 3;
	capture_score[bB_type][wR_type] = 100 + 5 - 3;
	capture_score[bR_type][wR_type] = 100 + 5 - 5;
	capture_score[bQ_type][wR_type] = 100 + 5 - 9;
	capture_score[bK_type][wR_type] = 100 + 5 - 10;

	capture_score[bP_type][wB_type] = 100 + 3 - 1;
	capture_score[bN_type][wB_type] = 100 + 3 - 3;
	capture_score[bB_type][wB_type] = 100 + 3 - 3;
	capture_score[bR_type][wB_type] = 100 + 3 - 5;
	capture_score[bQ_type][wB_type] = 100 + 3 - 9;
	capture_score[bK_type][wB_type] = 100 + 3 - 10;

	capture_score[bP_type][wN_type] = 100 + 3 - 1;
	capture_score[bN_type][wN_type] = 100 + 3 - 3;
	capture_score[bB_type][wN_type] = 100 + 3 - 3;
	capture_score[bR_type][wN_type] = 100 + 3 - 5;
	capture_score[bQ_type][wN_type] = 100 + 3 - 9;
	capture_score[bK_type][wN_type] = 100 + 3 - 10;

	capture_score[bP_type][wP_type] = 100 + 1 - 1;
	capture_score[bN_type][wP_type] = 100 + 1 - 3;
	capture_score[bB_type][wP_type] = 100 + 1 - 3;
	capture_score[bR_type][wP_type] = 100 + 1 - 5;
	capture_score[bQ_type][wP_type] = 100 + 1 - 9;
	capture_score[bK_type][wP_type] = 100 + 1 - 10;

	//default value is 500. Can be altered for different engine performance (higher = slower but stronger)
	search_depth_delta_time_max = 500;

	showDebugInfoDurinPlay = false;
}

void setUp(BOARD *board, const char FEN[])
{
	int index;

	//Insert pieces on board
	index = insertPiecesFromFEN(board, FEN);
	index = insertSideToPlayFromFEN(board, FEN, index);
	index = insertCastlePermsFromFEN(board, FEN, index);
	index = insertEnPassantSquareFromFEN(board, FEN, index);
	index = insertHalfMovesFromFEN(board, FEN, index);

	//Check that bitboards are correctly set up
	ensureValidBitboards(board);
}

static int insertPiecesFromFEN(BOARD *board, const char FEN[])
{
	int index = 0;
	int square_index = 0;
	char currChar;
	
	do
	{
		currChar = FEN[index];

		switch (currChar)
		{
		case '/':
		case ' ':
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
			square_index += (int)(currChar - '0');
			break;
		case 'r':
			insertPieceFromFEN(board, bR1, bR_type, rook_knight_bishop_cat, bP1, square_index);
			square_index++;
			break;
		case 'n':
			insertPieceFromFEN(board, bN1, bN_type, rook_knight_bishop_cat, bP1, square_index);
			square_index++;
			break;
		case 'b':
			insertPieceFromFEN(board, bB1, bB_type, rook_knight_bishop_cat, bP1, square_index);
			square_index++;
			break;
		case 'q':
			insertPieceFromFEN(board, bQ, bQ_type, queen_cat, bP1, square_index);
			square_index++;
			break;
		case 'k':
			insertPieceFromFEN(board, bK, bK_type, king_cat, bP1, square_index);
			square_index++;
			break;
		case 'p':
			insertPieceFromFEN(board, bP1, bP_type, pawn_cat, bP1, square_index);
			square_index++;
			break;
		case 'R':
			insertPieceFromFEN(board, wR1, wR_type, rook_knight_bishop_cat, wP1, square_index);
			square_index++;
			break;
		case 'N':
			insertPieceFromFEN(board, wN1, wN_type, rook_knight_bishop_cat, wP1, square_index);
			square_index++;
			break;
		case 'B':
			insertPieceFromFEN(board, wB1, wB_type, rook_knight_bishop_cat, wP1, square_index);
			square_index++;
			break;
		case 'Q':
			insertPieceFromFEN(board, wQ, wQ_type, queen_cat, wP1, square_index);
			square_index++;
			break;
		case 'K':
			insertPieceFromFEN(board, wK, wK_type, king_cat, wP1, square_index);
			square_index++;
			break;
		case 'P':
			insertPieceFromFEN(board, wP1, wP_type, pawn_cat, wP1, square_index);
			square_index++;
			break;
		default:
			printf("ERROR: Unexpected tolken: %c\n", currChar);
			ERROR
		}

		index++;

	} while (currChar != ' ' && index < MAX_FEN_CHARS);

	if (square_index != NUMBER_OF_SQUARES)
	{
		printf("ERROR: Wrong number of inputs from FEN.");
		ERROR
	}

	return index;
}

static void insertPieceFromFEN(BOARD *board, const int piece, const int pieceType, const int pieceCatagory, const int firstPawn, const int square)
{
	int piece_insertions = 0;
	int dual_square_placement = false;

	//Try first piece slot
	if (board->piecePositions[piece] == no_square && pieceCatagory != pawn_cat)
	{
		board->piecePositions[piece] = square;
		if (board->chessBoard[square] != no_piece)
		{
			dual_square_placement = true;
		}
		board->chessBoard[square] = piece;
		board->pieceTypes[piece] = pieceType;
		updateBitBoardFromInsertedPiece(board, piece, square);
		piece_insertions++;
	}
	//Try second piece slot
	else if (board->piecePositions[piece+1] == no_square && (pieceCatagory == rook_knight_bishop_cat))
	{
		board->piecePositions[piece+1] = square;
		if (board->chessBoard[square] != no_piece)
		{
			dual_square_placement = true;
		}
		board->chessBoard[square] = piece+1;
		board->pieceTypes[piece+1] = pieceType;		
		updateBitBoardFromInsertedPiece(board, piece, square);
		piece_insertions++;
	}
	//Try promoted pawn
	else
	{
		int i;
		for (i = 0; i < MAX_NO_OF_PAWNS; i++)
		{
			if (board->piecePositions[firstPawn + i] == no_square && pieceCatagory != king_cat)
			{
				board->piecePositions[firstPawn + i] = square;
				if (board->chessBoard[square] != no_piece)
				{
					dual_square_placement = true;
				}
				board->chessBoard[square] = firstPawn + i;
				board->pieceTypes[firstPawn + i] = pieceType;				
				updateBitBoardFromInsertedPiece(board, firstPawn + i, square);
				piece_insertions++;
				break;
			}
		}
	}

	if (dual_square_placement)
	{
		printf("ERROR: Square already assigned");
		ERROR
	}

	if (piece_insertions != 1)
	{
		printf("ERROR: Piece could not be inserted, or it was inserted more than once. Bad FEN.\n");
		ERROR
	}
}

static int insertSideToPlayFromFEN(BOARD* board, const char FEN[], const int index)
{
	int readStartIndex = index;
	//read past any white space
	while (FEN[readStartIndex] == ' ')
	{
		readStartIndex++;
	}
	if (FEN[readStartIndex] == 'w')
	{
		board->sideToPlay = side_to_play_white;
	}
	else if(FEN[readStartIndex] == 'b')
	{
		board->sideToPlay = side_to_play_black;
	}
	else
	{
		printf("ERROR, could not read side to play char.");
		ERROR
	}

	//increment readStartIndex before returning
	readStartIndex++;
	return readStartIndex;
}

static int insertCastlePermsFromFEN(BOARD* board, const char FEN[], const int index)
{
	int readStartIndex = index;
	//read past any white space
	while (FEN[readStartIndex] == ' ')
	{
		readStartIndex++;
	}

	while (FEN[readStartIndex] != ' ' && readStartIndex < MAX_FEN_CHARS)
	{
		switch (FEN[readStartIndex])
		{
			case '-':
				board->castlePerm = castle_null;
				break;
			case 'Q':
				board->castlePerm ^= castle_KQ;
				break;
			case 'K':
				board->castlePerm ^= castle_KK;
				break;
			case 'q':
				board->castlePerm ^= castle_kq;
				break;
			case 'k':
				board->castlePerm ^= castle_kk;
				break;
			default:
				printf("ERROR: unknown castle perm character %c\n", FEN[readStartIndex]);
				ERROR
		}
		readStartIndex++;
	}
	


	return readStartIndex;
}

static int insertEnPassantSquareFromFEN(BOARD* board, const char FEN[], const int index)
{
	int readStartIndex = index;
	//read past any white space
	while (FEN[readStartIndex] == ' ')
	{
		readStartIndex++;
	}

	if (FEN[readStartIndex] == '-')
	{
		board->enPassantSquare = no_square;
		readStartIndex++;
	}
	else
	{
		board->enPassantSquare = squareStringToSquare(&FEN[readStartIndex]);
		readStartIndex += 2;
	}


	return readStartIndex;
}

static int insertHalfMovesFromFEN(BOARD* board, const char FEN[], const int index)
{
	int readStartIndex = index;
	//read past any white space
	while (FEN[readStartIndex] == ' ')
	{
		readStartIndex++;
	}

	int digitsInNumber = 0;
	while (FEN[readStartIndex] != ' ' && readStartIndex < MAX_FEN_CHARS)
	{
		digitsInNumber++;
		readStartIndex++;
	}
	//Allow a maximum of 9999 moves
	ASSERT(digitsInNumber > 0 && digitsInNumber <= 4)

	int i;
	for (i = 1; i <= digitsInNumber; i++)
	{

		board->halfMoves += (int)(FEN[readStartIndex - i] - '0') * (int)(pow(10, i - 1)+0.5);
	}

	ASSERT(board->halfMoves >= 0 && board->halfMoves < 9999)

	return readStartIndex;
}

static void updateBitBoardFromInsertedPiece(BOARD *board, const int piece, const int squareTo)
{
	board->bitBoards[board->pieceTypes[piece]] ^= (1ULL << squareTo);
	if (colourOfPiece[piece] == white_colour)
	{
		board->bitBoards[allWhite_type] ^= (1ULL << squareTo);
	}
	else
	{
		board->bitBoards[allBlack_type] ^= (1ULL << squareTo);
	}
}

static void ensureValidBitboards(BOARD *board)
{	
	int square;
	for (square = 0; square < NUMBER_OF_SQUARES; square++)
	{
		if (board->chessBoard[square] != no_piece)
		{							
			//Check that the bit on the bitboard for this pawn is set to 1			
			ASSERT((board->bitBoards[board->pieceTypes[board->chessBoard[square]]] & bitSquares[square]) == bitSquares[square])
				
			if (colourOfPiece[board->chessBoard[square]] == black_colour)
			{
				ASSERT((board->bitBoards[allBlack_type] & bitSquares[square]) == bitSquares[square])
			}
			else
			{
				ASSERT((board->bitBoards[allWhite_type] & bitSquares[square]) == bitSquares[square])
			}
				
		}			
	}
}

static void sortPawns(BOARD *board)
{
	int sq;
	for (sq = 0; sq < NUMBER_OF_SQUARES; sq++)
	{
		if (board->chessBoard[sq] != no_piece)
		{

		}
	}
}