#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED

#include "stdio.h"
#include "global.h"
#include "Debug.h"
#include "Error.h"
#include "PiecesAndSquares.h"
#include "Search.h"

#define getMoveBit64(movePiece, capturedPiece, fromSquare, toSquare, isCastelingMove, pawnPromotionType, isEnpassCapture, enpassSquareNew, enpassSquareHistory, castelingPermHistory, halfmoveHistory, enPassCapturedPieceSquare) \
(movePiece | (U64)capturedPiece << 6 | (U64)fromSquare << 12 | (U64)toSquare << 18 | (U64)isCastelingMove << 24 | (U64)pawnPromotionType << 25 | (U64)isEnpassCapture << 29 | (U64)enpassSquareNew << 30 | (U64)enpassSquareHistory << 37 | (U64)castelingPermHistory << 44 | (U64)halfmoveHistory << 48 | (U64)enPassCapturedPieceSquare << 55)

//get data from MOVE.move
#define getMovePieceFromMOVE(move) (move & bitMask_6)
#define getCapturedPieceFromMOVE(move) ((move >> 6) & bitMask_6)
#define getFromSquareFromMOVE(move) ((move >> (U64)12) & bitMask_6)
#define getToSquareFromMOVE(move) ((move >> (U64)18) & bitMask_6)
#define getIsCastelingMoveFromMOVE(move) ((move >> (U64)24) & bitMask_1)
#define getPawnPromotionTypeFromMOVE(move) ((move >> (U64)25)& bitMask_4)
#define getIsEnpassCaptureFromMOVE(move) ((move >> (U64)29) & bitMask_1)
#define getEnpassSquareNewFromMOVE(move) ((move >> (U64)30) & bitMask_7)
#define getEnpassSquareHistoryFromMOVE(move) ((move >> (U64)37) & bitMask_7)
#define getCastelingPermHistoryFromMOVE(move) ((move >> (U64)44) & bitMask_4)
#define getHalfmoveHistoryHistoryFromMOVE(move) ((move >> (U64)48) & bitMask_7)
#define getEnPassCapturedPieceSquareFromMOVE(move) ((move >> (U64)55) & bitMask_7)

int squareStringToSquare(const char * squareString);
static void addMoveToList(MOVE_LIST *list, const BOARD *board, const int movePiece, const int capturedPiece, const int fromSquare, const int toSquare, const int isCastelingMove, const int pawnPromotionType, const int isEnpassCapture, const int enpassSquareNew);
int makeMove(BOARD *board, const MOVE move);
void unMakeMove(BOARD *board, const MOVE move);
int isSquareUnderAttack(const int square, const int attackingSide, const BOARD *board);
void getAllConceivableMoves(const BOARD *board, MOVE_LIST *list);
static void getAllLeagalBlackMoves(const BOARD *board, MOVE_LIST *list);
static void getAllLeagalWhiteMoves(const BOARD *board, MOVE_LIST *list);
static void getBlackPawnMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int piece);
static void getBlackRookMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getBlackKnightMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getBlackBishopMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getBlackQueenMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getBlackKingMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getWhitePawnMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getWhiteRookMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getWhiteKnightMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getWhiteBishopMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getWhiteQueenMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);
static void getWhiteKingMoves(const BOARD *board, MOVE_LIST *list, const int fromSquare, const int movePiece);

static U64 getCrossAttackPatternBits(const int square);
static U64 getKnightAttackPatternBits(const int square);
static U64 getKingAttackPatternBits(const int square);
U64 getWhitePawnAttackPatternBits(const int square);
U64 getBlackPawnAttackPatternBits(const int square);
static U64 getStraightUdAttackPatternBits(const int square);
static U64 getStraightRlAttackPatternBits(const int square);
static U64 getDiagonalUrDlAttackPatternBits(const int square);
static U64 getDiagonalUlDrAttackPatternBits(const int square);
static int isQueenOrBistop_UrDl_Attacked(const BOARD *board, const int square, const int allAttackingType, const U64 attacking_bishop_combined_w_queen_bitboard);
static int isQueenOrBistop_UlDr_Attacked(const BOARD *board, const int square, const int allAttackingType, const U64 attacking_bishop_combined_w_queen_bitboard);
static int isQueenOrRook_UD_Attacked(const BOARD *board, const int square, const int allAttackingType, const U64 attacking_rook_combined_w_queen_bitboard);
static int isQueenOrRook_RL_Attacked(const BOARD *board, const int square, const int allAttackingType, const U64 attacking_rook_combined_w_queen_bitboard);


#endif 