#include "Print.h"



void printCurrentBitVersion()
{
	if (sizeof(void*) == 4)
	{
		printf("Running 32 bit version\n");
	}
	else if (sizeof(void*) == 8)
	{
		printf("Running 64 bit version\n");
	}
	else
	{
		printf("Unknown bit version");
	}
}

void printBitBoard(const U64 bits)
{
	int i;
	for (i = 0; i < 8 * (sizeof(bits)); i++)
	{
		if (bits & (unsigned long long int) 1 << i)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		if ((i + 1) % 8 == 0)
		{
			printf("\n");
		}
	}
}

void printU64asBits(const U64 bits)
{
	int i;
	for (i = 63; i >= 0; i--)
	{
		if (bits & (1ULL << i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void printChessBoard(const BOARD *board)
{
	int i;
	int j;
	printf("\n");
	printf("   |---------------------------------|\n");
	for (i = 0; i < (NUMBER_OF_SQUARES / 8); i++) //print all rows
	{
		for (j = 0; j < (NUMBER_OF_SQUARES / 8); j++)
		{
			if (j == 0)
			{
				printf("%d  | ", (8 - i));
			}
			
			printf("%s  ", getChessPieceTypeString(board->pieceTypes[board->chessBoard[j + 8 * i]]));

			if (j == (NUMBER_OF_SQUARES / 8 - 1))
			{
				printf("|");
			}
		}
		printf("\n   |");
		
		if (i != (NUMBER_OF_SQUARES / 8) - 1)
		{
			printf("                                 |\n");
		}
	}
	printf("---------------------------------|\n");
	printf("     A   B   C   D   E   F   G   H\n");
	printf("\n");
}

void printChessBoard_dbg(const BOARD *board)
{
	int i;
	int j;
	printf("\n");
	printf("   |-------------------------------------------------|\n");
	for (i = 0; i < (NUMBER_OF_SQUARES / 8); i++) //print all rows
	{
		for (j = 0; j < (NUMBER_OF_SQUARES / 8); j++)
		{
			if (j == 0)
			{
				printf("%d  | ", (8 - i));
			}

			printf("%s  ", getChessPieceString(board->chessBoard[j + 8 * i]));
			int len = strlen(getChessPieceString(board->chessBoard[j + 8 * i]));
			int k;
			for (k = len; k < 4; k++)
			{
				printf(" ");
			}

			if (j == (NUMBER_OF_SQUARES / 8 - 1))
			{
				printf("|");
			}
		}
		printf("\n   |");

		if (i != (NUMBER_OF_SQUARES / 8) - 1)
		{
			printf("                                                 |\n");
		}
	}
	printf("-------------------------------------------------|\n");
	printf("      A     B     C     D     E     F     G     H\n");
	printf("\n");
}

void printMove(const BOARD *board, const MOVE *move)
{
	printf("MP: %s", getChessPieceString(getMovePieceFromMOVE(move->move)));
	printf("(%s) ", getChessPieceTypeString(board->pieceTypes[getMovePieceFromMOVE(move->move)]));
	printf("CP: %s", getChessPieceString(getCapturedPieceFromMOVE(move->move)));
	printf("(%s) ", getChessPieceTypeString((board->pieceTypes[getCapturedPieceFromMOVE(move->move)])));
	printf("Move: %s", getSquareString(getFromSquareFromMOVE(move->move)));
	printf("%s ", getSquareString(getToSquareFromMOVE(move->move)));
	printf("IsCastleMove: %llu ", getIsCastelingMoveFromMOVE(move->move));
	printf("PawnPromType: %s ", getChessPieceTypeString(getPawnPromotionTypeFromMOVE(move->move)));
	printf("IsEnpassCapture: %llu ", getIsEnpassCaptureFromMOVE(move->move));
	printf("EnpassSqNew: %s", getSquareString(getEnpassSquareNewFromMOVE(move->move)));
	printf(" EnpassSqHistory: %s", getSquareString(getEnpassSquareHistoryFromMOVE(move->move)));
	printf(" CastlePermHistory: ");
	printBits_4(getCastelingPermHistoryFromMOVE(move->move));
	printf(" HalfMoveHistory: %llu", getHalfmoveHistoryHistoryFromMOVE(move->move));
	printf(" EnPassCaptPieceSq: %s", getSquareString(getEnPassCapturedPieceSquareFromMOVE(move->move)));
	printf("\n");
}

void printMoveList(const BOARD *board, const MOVE_LIST *list)
{
	
	int i;
	for (i = 0; i < list->numberOfMoves; i++)
	{
		printf("MP: %s", getChessPieceString(getMovePieceFromMOVE(list->moves[i].move)));
		printf("(%s) ", getChessPieceTypeString(board->pieceTypes[getMovePieceFromMOVE(list->moves[i].move)]));
		printf("CP: %s", getChessPieceString(getCapturedPieceFromMOVE(list->moves[i].move)));
		printf("(%s) ", getChessPieceTypeString((board->pieceTypes[getCapturedPieceFromMOVE(list->moves[i].move)])));
		printf("Move: %s", getSquareString(getFromSquareFromMOVE(list->moves[i].move)));
		printf("%s ", getSquareString(getToSquareFromMOVE(list->moves[i].move)));
		printf("IsCastleMove: %llu ", getIsCastelingMoveFromMOVE(list->moves[i].move));
		printf("PawnPromType: %s ", getChessPieceTypeString(getPawnPromotionTypeFromMOVE(list->moves[i].move)));
		printf("IsEnpassCapture: %llu ", getIsEnpassCaptureFromMOVE(list->moves[i].move));
		printf("EnpassSqNew: %s", getSquareString(getEnpassSquareNewFromMOVE(list->moves[i].move)));
		printf(" EnpassSqHistory: %s", getSquareString(getEnpassSquareHistoryFromMOVE(list->moves[i].move)));
		printf(" CastlePermHistory: ");
		printBits_4(getCastelingPermHistoryFromMOVE(list->moves[i].move));
		printf(" HalfMoveHistory: %llu", getHalfmoveHistoryHistoryFromMOVE(list->moves[i].move));
		printf(" EnPassCaptPieceSq: %s", getSquareString(getEnPassCapturedPieceSquareFromMOVE(list->moves[i].move)));
		printf(" MoveIndex %d", i);
		printf("\n");
	}
	printf("Number of moves in list: %d\n", list->numberOfMoves);
}

void printBoard_all(const BOARD *board)
{
	int i;

	printChessBoard_dbg(board);
	printf("Piece positions: \n");
	for (i = 0; i < NUMBER_OF_PIECES; i++)
	{
		printf("%s:%s ", getChessPieceString(i), getSquareString(board->piecePositions[i]));
		if (i == NUMBER_OF_PIECES / 2 + 1)
		{
			printf("\n");
		}
	}
	printf("\n");
	printf("Piece types: \n");
	for (i = 0; i < NUMBER_OF_PIECES; i++)
	{
		printf("%s:%s ", getChessPieceString(i), getChessPieceTypeString(board->pieceTypes[i]));
		if (i == NUMBER_OF_PIECES / 2 + 1)
		{
			printf("\n");
		}
	}
	printf("\n");
	if (board->sideToPlay == side_black)
	{
		printf("Side to play: Black\n");
	}
	else
	{
		printf("Side to play: White\n");
	}
	printf("Casteling perm: ");
	printBits_4(board->castlePerm);
	printf("\n");
	printf("En passant square: %s\n", getSquareString(board->enPassantSquare));
	printf("HalfMoves: %d\n", board->halfMoves);

	for (i = 0; i < NUMBER_OF_BIT_BOARDS-2; i++)
	{
		printf("Bitboard: %s\n", getChessPieceTypeString(i));
		printBitBoard(board->bitBoards[i]);
		printf("\n");
	}
	printf("Bitboard: AllBlack\n");
	printBitBoard(board->bitBoards[allBlack_type]);
	printf("\n");
	printf("Bitboard: AllWhite\n");
	printBitBoard(board->bitBoards[allWhite_type]);
	printf("\n");
}

void printBits_4(const int bits)
{

	int i;
	for (i = 3; i >= 0; i--)
	{
		if (bits & (1 << i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}

char * getChessPieceString(const int chessPiece)
{
	switch (chessPiece)
	{
		//BLACK PIECES
	case bR1:
		return "bR1";
	case bN1:
		return "bN1";
	case bB1:
		return "bB1";
	case bQ:
		return "bQ";
	case bK:
		return "bK";
	case bB2:
		return "bB2";
	case bN2:
		return "bN2";
	case bR2:
		return "bR2";
	case bP1:
		return "bP1";
	case bP2:
		return "bP2";
	case bP3:
		return "bP3";
	case bP4:
		return "bP4";
	case bP5:
		return "bP5";
	case bP6:
		return "bP6";
	case bP7:
		return "bP7";
	case bP8:
		return "bP8";

		//WHITE PIECES
	case wR1:
		return "wR1";
	case wN1:
		return "wN1";
	case wB1:
		return "wB1";
	case wQ:
		return "wQ";
	case wK:
		return "wK";
	case wB2:
		return "wB2";
	case wN2:
		return "wN2";
	case wR2:
		return "wR2";
	case wP1:
		return "wP1";
	case wP2:
		return "wP2";
	case wP3:
		return "wP3";
	case wP4:
		return "wP4";
	case wP5:
		return "wP5";
	case wP6:
		return "wP6";
	case wP7:
		return "wP7";
	case wP8:
		return "wP8";

		//EMPTY SQUARE
	case no_piece:
		return "[]";

	default:
		printf("ERROR: unknown piece: %d\n", chessPiece);
		ERROR
	}
}

char * getChessPieceTypeString(const int pieceType)
{

	//NON EMPTY SQUARE
	switch (pieceType)
	{
		//BLACK PIECES
	case bR_type:	
		return "bR";
	case bN_type:
		return "bN";
	case bB_type:
		return "bB";
	case bQ_type:
		return "bQ";
	case bK_type:
		return "bK";
	case bP_type:
		return "bP";

		//WHITE PIECES
	case wR_type:
		return "wR";
	case wN_type:
		return "wN";
	case wB_type:
		return "wB";
	case wQ_type:
		return "wQ";
	case wK_type:
		return "wK";
	case wP_type:
		return "wP";
	case no_piece_type:
		return "[]";
	default:
		printf("ERROR: unknown piece type: %d\n", pieceType);
		ERROR
	}
}

char * getSquareString(const int square)
{
	switch (square)
	{
	case A1:
		return "a1";
	case A2:
		return "a2";
	case A3:
		return "a3";
	case A4:
		return "a4";
	case A5:
		return "a5";
	case A6:
		return "a6";
	case A7:
		return "a7";
	case A8:
		return "a8";
	case B1:
		return "b1";
	case B2:
		return "b2";
	case B3:
		return "b3";
	case B4:
		return "b4";
	case B5:
		return "b5";
	case B6:
		return "b6";
	case B7:
		return "b7";
	case B8:
		return "b8";
	case C1:
		return "c1";
	case C2:
		return "c2";
	case C3:
		return "c3";
	case C4:
		return "c4";
	case C5:
		return "c5";
	case C6:
		return "c6";
	case C7:
		return "c7";
	case C8:
		return "c8";
	case D1:
		return "d1";
	case D2:
		return "d2";
	case D3:
		return "d3";
	case D4:
		return "d4";
	case D5:
		return "d5";
	case D6:
		return "d6";
	case D7:
		return "d7";
	case D8:
		return "d8";
	case E1:
		return "e1";
	case E2:
		return "e2";
	case E3:
		return "e3";
	case E4:
		return "e4";
	case E5:
		return "e5";
	case E6:
		return "e6";
	case E7:
		return "e7";
	case E8:
		return "e8";
	case F1:
		return "f1";
	case F2:
		return "f2";
	case F3:
		return "f3";
	case F4:
		return "f4";
	case F5:
		return "f5";
	case F6:
		return "f6";
	case F7:
		return "f7";
	case F8:
		return "f8";
	case G1:
		return "g1";
	case G2:
		return "g2";
	case G3:
		return "g3";
	case G4:
		return "g4";
	case G5:
		return "g5";
	case G6:
		return "g6";
	case G7:
		return "g7";
	case G8:
		return "g8";
	case H1:
		return "h1";
	case H2:
		return "h2";
	case H3:
		return "h3";
	case H4:
		return "h4";
	case H5:
		return "h5";
	case H6:
		return "h6";
	case H7:
		return "h7";
	case H8:
		return "h8";
	case no_square:
		return "[]";


	default:
		printf("ERROR: unknown square: %d\n", square);
		ERROR
	}
}