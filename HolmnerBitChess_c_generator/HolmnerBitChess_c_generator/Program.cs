using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HolmnerBitChess_c_generator
{
    class Program
    {
        static string inputCodeFolderPath = @"..\..\code_in\";
        static string outputCodeFolderPath = @"..\..\code_out\";

        static void Main(string[] args)
        {
            //generateBlackPawnMoveLogic("black_pawn_move_logic.txt");
            //generateBlackBistopMoveLogic("black_bishop_move_logic.txt");
            //generateBlackRookMoveLogic("black_rook_move_logic.txt");
            //generateBlackKnightMoveLogic("black_knight_move_logic.txt");
            //generateBlackQueenMoveLogic("black_queen_move_logic.txt");
            //generateBlackKingMoveLogic("black_king_move_logic.txt");
            //generateWhitePawnMoveLogic("white_pawn_move_logic.txt");
            //generateWhiteBishopMoveLogic("white_bishop_move_logic.txt");
            //generateWhiteKingMoveLogic("white_king_move_logic.txt");
            //generateWhiteKnightMoveLogic("white_knight_move_logic.txt");
            //generateWhiteRookMoveLogic("white_rook_move_logic.txt");
            //generateWhiteQueenMoveLogic("white_queen_move_logic.txt");
            //generateKnightBitMovePattern("knight_move_pattern_bits.txt");
            //generateKingBitMovePattern("king_move_pattern_bits.txt");
            generateCrossBitMovePattern("cross_move_pattern_bits.txt");
            //generateWhitePawnBitMovePattern("pawn_white_move_pattern_bits.txt");
            //generateBlackPawnBitMovePattern("pawn_black_move_pattern_bits.txt");
            //generateDiagonalUrDlBitMovePattern("diagonal_UrDl_move_pattern_bits.txt");
            //generateDiagonalUlDrBitMovePattern("diagonal_UlDr_move_pattern_bits.txt");
            //generateStraightUDBitMovePattern("straight_UD_move_pattern_bits.txt");
            //generateStraightRLBitMovePattern("straight_RL_move_pattern_bits.txt");
            //generateQueenBisop_UrDl_AttackLogic("queen_bishop_UrDl_attack_logic.txt");
            //generateQueenBisop_UlDr_AttackLogic("queen_bishop_UlDr_attack_logic.txt");
            //generateQueenRook_UD_AttackLogic("queen_rook_UD_attack_logic.txt");
            //generateQueenRook_RL_AttackLogic("queen_rook_RL_attack_logic.txt");
        }

        static void generateWhitePawnMoveLogic(string outputFileName)
        {
            System.IO.File.Delete(outputCodeFolderPath + outputFileName);
            System.IO.StreamWriter file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
            file_out.WriteLine("\tswitch(fromSquare)");
            file_out.WriteLine("\t{");
            file_out.Close();

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                    file_out.WriteLine("\t\tcase " + boardIndexToString(file, rank) + ":");
                    file_out.Close();

                    if (isInsideBoard(file, rank + 1))
                    {
                        if (rank == 6) FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_d_no_move.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + 1));
                        else FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_d.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + 1));
                        if (rank == 1)
                        {
                            FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "white_pawn_dd.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + 2), boardIndexToString(file, rank + 1));
                        }

                        if (rank == 6)
                        {
                            FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_d_promote.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + 1));
                        }

                        file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                        file_out.WriteLine("\t\t\t}");
                        file_out.Close();

                        if (isInsideBoard(file - 1, rank - 1))
                        {
                            if (rank == 6) FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_dldr_no_move.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - 1, rank + 1));
                            else FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_dl.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - 1, rank + 1));
                            if (rank == 6)
                            {
                                FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_ld_dr_promote.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - 1, rank + 1));
                            }

                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\t}");
                            file_out.Close();
                        }

                        if (isInsideBoard(file + 1, rank + 1))
                        {
                            if (rank == 6) FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_dldr_no_move.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank + 1));
                            else FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_dr.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank + 1));
                            if (rank == 6)
                            {
                                FileReadWrite.readAndAppend(inputCodeFolderPath + "white_pawn_ld_dr_promote.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank + 1));
                            }

                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\t}");
                            file_out.Close();
                        }

                        if (rank == 4)
                        {
                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\tif (board->enPassantSquare != no_square)");
                            file_out.WriteLine("\t\t\t{");
                            file_out.Close();

                            bool elseIfBool = false;
                            if (isInsideBoard(file - 1, rank + 1))
                            {
                                FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "white_pawn_enPass_dl.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - 1, rank + 1), boardIndexToString(file - 1, rank));
                                elseIfBool = true;
                            }

                            if (isInsideBoard(file + 1, rank + 1))
                            {
                                if (elseIfBool)
                                {
                                    FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "white_pawn_enPass_elif_dr.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank + 1), boardIndexToString(file + 1, rank));
                                }
                                else
                                {
                                    FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "white_pawn_enPass_dr.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank + 1), boardIndexToString(file + 1, rank));
                                }
                            }

                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\t}");
                            file_out.Close();
                        }


                    }

                    file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                    file_out.WriteLine("\t\t\tbreak;");
                    file_out.Close();
                }
            }

            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
            file_out.WriteLine("\t}");
            file_out.Close();

        }

        static void generateWhiteBishopMoveLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");

                    while (isInsideBoard(file + stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank - k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank - k), k);
                    }
                    stepSize = 1;





                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateWhiteKingMoveLogic(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            int addx;
            int addy;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");
                    if (file == 4 && rank == 0)
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_king_castle.txt", outputCodeFolderPath + outputFileName, "");

                    }

                    addx = 1;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 0;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = 0;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 0;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = 0;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateWhiteKnightMoveLogic(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            int addx;
            int addy;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");



                    addx = 2;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = 2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = 2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -2;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -2;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = -2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = -2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 2;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }




                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateWhiteRookMoveLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");
                    string repl_this = "";
                    string repl_with = "";
                    while (isInsideBoard(file, rank + stepSize))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + stepSize), stepSize - 1, repl_this, repl_with);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + k), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file, rank - stepSize))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - stepSize), stepSize - 1, repl_this, repl_with);

                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - k), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank), stepSize - 1, repl_this, repl_with);


                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank), stepSize - 1, repl_this, repl_with);


                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank), k, repl_this, repl_with);
                    }
                    stepSize = 1;





                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateWhiteQueenMoveLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");

                    while (isInsideBoard(file + stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank - k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank - k), k);
                    }
                    stepSize = 1;

                    while (isInsideBoard(file, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "white_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank), k);
                    }
                    stepSize = 1;



                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateBlackPawnMoveLogic(string outputFileName)
        {
            System.IO.File.Delete(outputCodeFolderPath + outputFileName);
            System.IO.StreamWriter file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
            file_out.WriteLine("\tswitch(fromSquare)");
            file_out.WriteLine("\t{");
            file_out.Close();

            for (int file = 0; file < 8; file++)
            {
                for(int rank = 0; rank < 8; rank++)
                {                    
                    file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                    file_out.WriteLine("\t\tcase " + boardIndexToString(file,rank) + ":");
                    file_out.Close();

                    if (isInsideBoard(file, rank - 1))
                    {
                        if(rank == 1)FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_d_no_move.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - 1));
                        else FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_d.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - 1));
                        if (rank == 6)
                        {
                            FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "black_pawn_dd.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - 2), boardIndexToString(file, rank - 1));
                        }

                        if(rank == 1)
                        {
                            FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_d_promote.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - 1));
                        }

                        file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                        file_out.WriteLine("\t\t\t}");
                        file_out.Close();

                        if (isInsideBoard(file-1, rank-1))
                        {
                            if (rank == 1) FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_dldr_no_move.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - 1, rank - 1));
                            else FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_dl.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file-1, rank - 1));
                            if (rank == 1)
                            {
                                FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_ld_dr_promote.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file-1, rank - 1));
                            }

                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\t}");
                            file_out.Close();
                        }

                        if (isInsideBoard(file + 1, rank - 1))
                        {
                            if (rank == 1) FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_dldr_no_move.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank - 1));
                            else FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_dr.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank - 1));
                            if (rank == 1)
                            {
                                FileReadWrite.readAndAppend(inputCodeFolderPath + "black_pawn_ld_dr_promote.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank - 1));
                            }

                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\t}");
                            file_out.Close();
                        }

                        if(rank == 3)
                        {
                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\tif (board->enPassantSquare != no_square)");
                            file_out.WriteLine("\t\t\t{");    
                            file_out.Close();

                            bool elseIfBool = false;
                            if(isInsideBoard(file - 1, rank - 1))
                            {
                                FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "black_pawn_enPass_dl.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - 1, rank - 1), boardIndexToString(file - 1, rank));
                                elseIfBool = true;
                            }

                            if (isInsideBoard(file + 1, rank - 1))
                            {
                                if(elseIfBool)
                                {
                                    FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "black_pawn_enPass_elif_dr.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank - 1), boardIndexToString(file + 1, rank));
                                }
                                else
                                {
                                    FileReadWrite.readAndAppend_twoSq(inputCodeFolderPath + "black_pawn_enPass_dr.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + 1, rank - 1), boardIndexToString(file + 1, rank));
                                }                                
                            }

                            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                            file_out.WriteLine("\t\t\t}");
                            file_out.Close();
                        }
                        
                        
                    }

                    file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
                    file_out.WriteLine("\t\t\tbreak;");
                    file_out.Close();
                }
            }

            file_out = System.IO.File.AppendText(outputCodeFolderPath + outputFileName);
            file_out.WriteLine("\t}");
            file_out.Close();

        }

        static void generateBlackRookMoveLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");
                    string repl_this = "";
                    string repl_with = "";
                    while (isInsideBoard(file, rank + stepSize))
                    {
                        if(file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";                            
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + stepSize), stepSize - 1, repl_this, repl_with);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + k), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file, rank - stepSize))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - stepSize), stepSize - 1, repl_this, repl_with);
                                               
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - k), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank), stepSize - 1, repl_this, repl_with);

                        
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank), stepSize - 1, repl_this, repl_with);

                        
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank), k, repl_this, repl_with);
                    }
                    stepSize = 1;





                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateBlackKnightMoveLogic(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            int addx;
            int addy;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");



                    addx = 2;
                    addy = 1;
                    if(isInsideBoard(file+addx, rank+addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file+addx, rank+addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = 2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = 2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -2;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -2;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = -2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = -2;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 2;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }




                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateBlackBistopMoveLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");

                    while(isInsideBoard(file+stepSize, rank+stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank + stepSize), stepSize-1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k+1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank + k), k );
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank - k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank - k), k);
                    }
                    stepSize = 1;





                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateBlackQueenMoveLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");

                    while (isInsideBoard(file + stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank - k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank - k), k);
                    }
                    stepSize = 1;

                    while (isInsideBoard(file, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file + stepSize, rank))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank), k);
                    }
                    stepSize = 1;



                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateBlackKingMoveLogic(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            int addx;
            int addy;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(fromSquare)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");
                    if(file == 4 && rank == 7)
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_king_castle.txt", outputCodeFolderPath + outputFileName, "");
                    
                    }

                    addx = 1;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 0;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = 1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = 0;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = -1;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 0;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = -1;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }
                    //NEXT DIRECTION//
                    addx = 1;
                    addy = 0;
                    if (isInsideBoard(file + addx, rank + addy))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "black_knight.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + addx, rank + addy));
                    }


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateKnightBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8,8];
                    int offsX;
                    int offsY;

                    offsX = 2;
                    offsY = 1;
                    if(isInsideBoard(file+offsX, rank+offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = 1;
                    offsY = 2;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = -1;
                    offsY = 2;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = -2;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = -2;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = -1;
                    offsY = -2;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = 1;
                    offsY = -2;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    //NEXT DIRECTION//
                    offsX = 2;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    

                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateDiagonalUrDlBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX = 1;
                    int offsY = 1;

                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsX += 1;
                        offsY += 1;                        
                    }

                    offsX = -1;
                    offsY = -1;
                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsX -= 1;
                        offsY -= 1;
                    }

                    

                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateDiagonalUlDrBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX = -1;
                    int offsY = 1;

                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsX -= 1;
                        offsY += 1;
                    }

                    offsX = 1;
                    offsY = -1;
                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsX += 1;
                        offsY -= 1;
                    }



                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateStraightUDBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX = 0;
                    int offsY = 1;

                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsY += 1;
                    }

                    offsX = 0;
                    offsY = -1;
                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsY -= 1;
                    }



                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateStraightRLBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX = 1;
                    int offsY = 0;

                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsX += 1;
                    }

                    offsX = -1;
                    offsY = 0;
                    while (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                        offsX -= 1;
                    }



                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateKingBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX;
                    int offsY;

                    offsX = 1;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = 0;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = -1;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = -1;
                    offsY = 0;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = -1;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = 0;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = 1;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = 1;
                    offsY = 0;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateCrossBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX;
                    int offsY;

                   
                    offsX = 0;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    

                    offsX = -1;
                    offsY = 0;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    

                    offsX = 0;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    

                    offsX = 1;
                    offsY = 0;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateBlackPawnBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX;
                    int offsY;

                    offsX = 1;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = -1;
                    offsY = 1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }
                    

                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateWhitePawnBitMovePattern(string outputFileName)
        {
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");


                    int[,] bitPatternMatrix = new int[8, 8];
                    int offsX;
                    int offsY;

                    offsX = 1;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }

                    offsX = -1;
                    offsY = -1;
                    if (isInsideBoard(file + offsX, rank + offsY))
                    {
                        bitPatternMatrix[file + offsX, rank + offsY] = 1;
                    }


                    string hexVal = HexBinaryHandler.bitPatternToHex(bitPatternMatrix);

                    FileReadWrite.writeToFile(path, "\t\t\treturn " + hexVal + ";");


                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
        }

        static void generateQueenBisop_UrDl_AttackLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");

                    while (isInsideBoard(file + stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_bishop.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        
                    }
                    stepSize = 1;

                   

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_bishop.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                      //  FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank - k), k);
                    }
                    stepSize = 1;

                  




                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
                
            }

            FileReadWrite.writeToFile(path, "\t}");
            FileReadWrite.writeToFile(path, "\treturn false;");
        }

        static void generateQueenBisop_UlDr_AttackLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");

                   
                    while (isInsideBoard(file - stepSize, rank + stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_bishop.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank + stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        // FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank + k), k);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                   
                    while (isInsideBoard(file + stepSize, rank - stepSize))
                    {
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_bishop.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank - stepSize), stepSize - 1);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        //   FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank - k), k);
                    }
                    stepSize = 1;





                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
            FileReadWrite.writeToFile(path, "\treturn false;");
        }

        static void generateQueenRook_UD_AttackLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");
                    string repl_this = "";
                    string repl_with = "";
                    while (isInsideBoard(file, rank + stepSize))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_rook.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + stepSize), stepSize - 1, repl_this, repl_with);
                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                       // FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank + k), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file, rank - stepSize))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_rook.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - stepSize), stepSize - 1, repl_this, repl_with);

                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                    //    FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file, rank - k), k, repl_this, repl_with);
                    }
                    stepSize = 1;
                    




                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
            FileReadWrite.writeToFile(path, "\treturn false;");
        }

        static void generateQueenRook_RL_AttackLogic(string outputFileName)
        {
            int stepSize = 1;
            string path = outputCodeFolderPath + outputFileName;
            System.IO.File.Delete(path);
            FileReadWrite.writeToFile(path, "\tswitch(square)");
            FileReadWrite.writeToFile(path, "\t{ ");

            for (int file = 0; file < 8; file++)
            {
                for (int rank = 0; rank < 8; rank++)
                {
                    FileReadWrite.writeToFile(path, "\t\tcase " + boardIndexToString(file, rank) + ":");
                    string repl_this = "";
                    string repl_with = "";
                    
                    while (isInsideBoard(file + stepSize, rank))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_rook.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + stepSize, rank), stepSize - 1, repl_this, repl_with);


                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        //     FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file + k, rank), k, repl_this, repl_with);
                    }
                    stepSize = 1;

                    /////////NEXT DIRECTION////////
                    while (isInsideBoard(file - stepSize, rank))
                    {
                        if (file == 0 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xE)";
                        }
                        else if (file == 7 && rank == 7)
                        {
                            repl_this = "board->castlePerm";
                            repl_with = "(board->castlePerm & 0xD)";
                        }
                        else
                        {
                            repl_this = "";
                            repl_with = "";
                        }
                        FileReadWrite.readAndAppend(inputCodeFolderPath + "attacked_by_queen_rook.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - stepSize, rank), stepSize - 1, repl_this, repl_with);


                        stepSize++;
                    }
                    stepSize--;
                    for (int k = stepSize; k > 0; k--)
                    {
                        FileReadWrite.writeToFile(path, "}", k + 1);
                        //     FileReadWrite.readAndAppend(inputCodeFolderPath + "black_bishop_no_piece_else.txt", outputCodeFolderPath + outputFileName, boardIndexToString(file - k, rank), k, repl_this, repl_with);
                    }
                    stepSize = 1;





                    FileReadWrite.writeToFile(path, "\t\t\tbreak;");
                }
            }

            FileReadWrite.writeToFile(path, "\t}");
            FileReadWrite.writeToFile(path, "\treturn false;");
        }

        static void print64BitPatternMatrix(int[,] bits)
        {
            for(int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if(bits[i,j] == 0)
                    {
                        Console.Write("0");
                    }
                    else
                    {
                        Console.Write("1");
                    }
                }
                Console.Write("\n");
            }
            
        }

        static bool isInsideBoard(int i, int j)
        {
            if (i >= 0 && i <= 7 && j >= 0 && j <= 7) return true;
            return false;
        }

        static string boardIndexToString(int x, int y)
        {
            if (x < 0 || x > 8 || y < 0 || y > 8) throw new Exception();
            string returnString = "";
            returnString += intToLetter(x);
            returnString += (y + 1).ToString();
            return returnString;
        }

        static char intToLetter(int x)
        {
            switch (x)
            {
                case 0:
                    return 'A';
                case 1:
                    return 'B';
                case 2:
                    return 'C';
                case 3:
                    return 'D';
                case 4:
                    return 'E';
                case 5:
                    return 'F';
                case 6:
                    return 'G';
                case 7:
                    return 'H';
            }
            return ' ';
        }
    }
}


