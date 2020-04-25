#ifndef PIECESANDSQUARES_H_INCLUDED
#define PIECESANDSQUARES_H_INCLUDED

#include "Global.h"

#define EMPTY_BIT_BOARD 0x0


enum
{
	bR1, bR2, bN1, bN2, bB1, bB2, bQ, bK,
	bP1, bP2, bP3, bP4, bP5, bP6, bP7, bP8, 	
	wR1, wR2, wN1, wN2,	wB1, wB2, wQ, wK, 
	wP1, wP2, wP3, wP4, wP5, wP6, wP7, wP8,
	no_piece
};
#define FIRST_PIECE_BLACK bR1
#define LAST_PIECE_BLACK bP8
#define FIRST_PIECE_WHITE wR1
#define LAST_PIECE_WHITE wP8

enum
{
	black_colour, white_colour
};

//Piece colour (to enable stuff like if(colourOfPiece[piece] == black_piece) )
int colourOfPiece[NUMBER_OF_PIECES];

//Is pawn (to enable stuff like if(isPawn[piece] == true)
int isPawn[NUMBER_OF_PIECES];

//Piece types (used to determain promoted pawn types etc)
enum
{
	bP_type, bR_type, bN_type, bB_type, bQ_type, bK_type, wP_type, wR_type, wN_type, wB_type, wQ_type, wK_type, allWhite_type, allBlack_type, no_piece_type
};

//All squares represented at bitboard
U64 bitSquares[NUMBER_OF_SQUARES];
/*
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

*/


//Files and ranks
#define rank_1 0xff00000000000000
#define rank_2 0xff000000000000
#define rank_3 0xff0000000000
#define rank_4 0xff00000000
#define rank_5 0xff000000
#define rank_6 0xff0000
#define rank_7 0xff00
#define rank_8 0xff
#define file_A 0x0101010101010101
#define file_B 0x0202020202020202
#define file_C 0x0404040404040404
#define file_D 0x0808080808080808
#define file_E 0x1010101010101010
#define file_F 0x2020202020202020
#define file_G 0x4040404040404040
#define file_H 0x8080808080808080

//ALL CHESSBOARD SQUARES
#define A8 0
#define B8 1
#define C8 2
#define D8 3
#define E8 4
#define F8 5
#define G8 6
#define H8 7

#define A7 8
#define B7 9
#define C7 10
#define D7 11
#define E7 12
#define F7 13
#define G7 14
#define H7 15

#define A6 16
#define B6 17
#define C6 18
#define D6 19
#define E6 20
#define F6 21
#define G6 22
#define H6 23

#define A5 24
#define B5 25
#define C5 26
#define D5 27
#define E5 28
#define F5 29
#define G5 30
#define H5 31

#define A4 32
#define B4 33
#define C4 34
#define D4 35
#define E4 36
#define F4 37
#define G4 38
#define H4 39

#define A3 40
#define B3 41
#define C3 42
#define D3 43
#define E3 44
#define F3 45
#define G3 46
#define H3 47

#define A2 48
#define B2 49
#define C2 50
#define D2 51
#define E2 52
#define F2 53
#define G2 54
#define H2 55

#define A1 56
#define B1 57
#define C1 58
#define D1 59
#define E1 60
#define F1 61
#define G1 62
#define H1 63

//Outside board (where dead pieces land)
#define no_square 64

#endif