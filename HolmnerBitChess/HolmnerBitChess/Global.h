#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define true 1
#define false 0

#define MAX_NO_OF_PAWNS 8
#define MAX_NO_OF_KNIGHTS 10
#define MAX_NO_OF_BISHOPS 10
#define MAX_NO_OF_QUEENS 9

#define MAX_NO_OF_POSSIBLE_MOVES 128

#define NUMBER_OF_BIT_BOARDS 14

#define NUMBER_OF_SQUARES 64
#define NUMBER_OF_PIECES 32

#define bitMask_1 0x1
#define bitMask_4 0xf
#define bitMask_6 0x3f
#define bitMask_7 0x7f

#define startFEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"


enum
{
	side_to_play_black, side_to_play_white, side_to_play_undefined
};

enum
{
	side_black, side_white, side_undefined
};

//castle persmission bits
#define castle_KK 0x8
#define castle_KQ 0x4
#define castle_kk 0x2
#define castle_kq 0x1
#define castle_null 0x0

/*TYPEDEFS*/
typedef unsigned long long int U64;

typedef struct
{
	int chessBoard[NUMBER_OF_SQUARES];
	int piecePositions[NUMBER_OF_PIECES]; //last index will hold no_piece position (no_square)
	int pieceTypes[NUMBER_OF_PIECES+1]; //last index will hold no_piece piecetype
	int sideToPlay;
	//castle permissions -used as 4 bit binary number with order:  K Q k q 
	int castlePerm;
	int enPassantSquare;
	int halfMoves;
	
	//Bitboards	(bP,bR,bN,bB,bQ,bK,wP,wR,wN,wB,wQ,wK,allwhite,allblack)
	U64 bitBoards[NUMBER_OF_BIT_BOARDS];
} BOARD;

typedef struct
{
	int score;
	U64 move;

	/*STRUCTURE OF U64 move:
	0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0011 1111 -> movePiece (6bit)                  
	0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 1100 0000 -> capturedPiece (6bit)              
	0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0011 1111 0000 0000 0000 -> fromSquare (6bit)                 
	0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 1100 0000 0000 0000 0000 -> toSquare (6bit)                   
	0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0000 0000 0000 0000 0000 0000 -> isCastelingMove (1bit)            
	0000 0000 0000 0000 0000 0000 0000 0000 0001 1110 0000 0000 0000 0000 0000 0000 -> pawnPromotionType (4bit)           
	0000 0000 0000 0000 0000 0000 0000 0000 0010 0000 0000 0000 0000 0000 0000 0000 -> isEnpassCapture (1bit)            
	0000 0000 0000 0000 0000 0000 0001 1111 1100 0000 0000 0000 0000 0000 0000 0000 -> enpassSquareNew (7bit)            
	0000 0000 0000 0000 0000 1111 1110 0000 0000 0000 0000 0000 0000 0000 0000 0000 -> enpassSquareHistory (7bit)        
	0000 0000 0000 0000 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 -> castelingPermHistory (4bit)  
	0000 0000 0111 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 -> halfmoveHistory (7bit)
	0011 1111 1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 -> enPassCapturePieceSquare (7 bit)
	*/

}MOVE;

typedef struct
{
	int numberOfMoves;
	MOVE moves[MAX_NO_OF_POSSIBLE_MOVES];
}MOVE_LIST;

//Used in move ordering
int capture_score[12][10];

//used in search.c in getBestMove, can be altered for different performance of engine (default is 500)
int search_depth_delta_time_max;

int showDebugInfoDurinPlay;

#endif 
