#include "Solver.hpp"

//std::vector<Board> Solver::solve1(Board StartBoard)
//{
//    std::vector<Board> solvedBoards;
//    std::vector<Block> solutionBlocks;
//    std::vector<Block> playblocks = Board::getNotPlacedBlocks();
//
//    // Brute Force Solution
//
//    int check[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//    int trash;
//    for(int height0; height0 < 8; height0++)
//    {
//        if(!check[0]) break;
//        for(int width0; width0 < 8; width0++)
//        {
//            check[0] = playblocks[0].canPlace(height0, width0);
//            if(!check[0])
//            {
//                playblocks[0].rotate();
//                check[0] = playblocks[0].canPlace(height0, width0);
//            }
//            if(!check[0])
//            {
//                break;
//            }
//            trash = playblocks[0].place(height0, width0);
//            solutionBlocks.push_back(playblocks[0]);
//
//            for(int height1; height1 < 8; height1++)
//            {
//                if(!check[1]) break;
//                for(int width1; width1 < 8; width1++)
//                {
//                    check[1] = playblocks[1].canPlace(height1, width1);
//                    if(!check[1])
//                    {
//                        playblocks[1].rotate();
//                        check[1] = playblocks[1].canPlace(height1, width1);
//                    }
//                    if(!check[1])
//                    {
//                        break;
//                    }
//                    trash = playblocks[1].place(height1, width1);
//                    solutionBlocks.push_back(playblocks[1]);
//                    ///
//                    for(int height2; height2 < 8; height2++)
//                    {
//                        if(!check[2]) break;
//                        for(int width2; width2 < 8; width2++)
//                        {
//                            check[2] = playblocks[2].canPlace(height2, width2);
//                            if(!check[2])
//                            {
//                                playblocks[2].rotate();
//                                check[2] = playblocks[2].canPlace(height2, width2);
//                            }
//                            if(!check[2])
//                            {
//                                break;
//                            }
//                            trash = playblocks[2].place(height2, width2);
//                            solutionBlocks.push_back(playblocks[2]);
//                            ///
//                            for(int height3; height3 < 8; height3++)
//                            {
//                                if(!check[3]) break;
//                                for(int width3; width3 < 8; width3++)
//                                {
//                                    check[3] = playblocks[3].canPlace(height3, width3);
//                                    if(!check[3])
//                                    {
//                                        playblocks[3].rotate();
//                                        check[3] = playblocks[3].canPlace(height3, width3);
//                                    }
//                                    if(!check[3])
//                                    {
//                                        break;
//                                    }
//                                    trash = playblocks[3].place(height3, width3);
//                                    solutionBlocks.push_back(playblocks[3]);
//                                    ///
//                                    for(int height4; height4 < 8; height4++)
//                                    {
//                                        if(!check[4]) break;
//                                        for(int width4; width4 < 8; width4++)
//                                        {
//                                            check[4] = playblocks[4].canPlace(height4, width4);
//                                            if(!check[4])
//                                            {
//                                                playblocks[4].rotate();
//                                                check[4] = playblocks[4].canPlace(height4, width4);
//                                            }
//                                            if(!check[4])
//                                            {
//                                                break;
//                                            }
//                                            trash = playblocks[4].place(height4, width4);
//                                            solutionBlocks.push_back(playblocks[4]);
//                                            ///
//                                            for(int height5; height5 < 8; height5++)
//                                            {
//                                                if(!check[5]) break;
//                                                for(int width5; width5 < 8; width5++)
//                                                {
//                                                    check[5] = playblocks[5].canPlace(height5, width5);
//                                                    if(!check[5])
//                                                    {
//                                                        playblocks[5].rotate();
//                                                        check[5] = playblocks[5].canPlace(height5, width5);
//                                                    }
//                                                    if(!check[5])
//                                                    {
//                                                        break;
//                                                    }
//                                                    trash = playblocks[5].place(height5, width5);
//                                                    solutionBlocks.push_back(playblocks[5]);
//                                                    ///
//                                                    for(int height6; height6 < 8; height6++)
//                                                    {
//                                                        if(!check[6]) break;
//                                                        for(int width6; width6 < 8; width6++)
//                                                        {
//                                                            check[6] = playblocks[6].canPlace(height6, width6);
//                                                            if(!check[6])
//                                                            {
//                                                                playblocks[6].rotate();
//                                                                check[6] = playblocks[6].canPlace(height6, width6);
//                                                            }
//                                                            if(!check[6])
//                                                            {
//                                                                break;
//                                                            }
//                                                            trash = playblocks[6].place(height6, width6);
//                                                            solutionBlocks.push_back(playblocks[6]);
//                                                            ///
//                                                            for(int height7; height7 < 8; height7++)
//                                                            {
//                                                                if(!check[7]) break;
//                                                                for(int width7; width7 < 8; width7++)
//                                                                {
//                                                                    check[7] = playblocks[7].canPlace(height7, width7);
//                                                                    if(!check[7])
//                                                                    {
//                                                                        playblocks[7].rotate();
//                                                                        check[7] = playblocks[7].canPlace(height7, width7);
//                                                                    }
//                                                                    if(!check[7])
//                                                                    {
//                                                                        break;
//                                                                    }
//                                                                    trash = playblocks[7].place(height7, width7);
//                                                                    solutionBlocks.push_back(playblocks[7]);
//                                                                    /// add to solvedBoards
//                                                                    Board Solution;
//                                                                    Solution.setBoard(solutionBlocks);
//                                                                    solvedBoards.push_back(Solution);
//                                                                }
//                                                            }
//                                                            ///
//                                                            playblocks[6].remove(height6, width6);
//                                                            solutionBlocks.pop_back();
//
//                                                        }
//                                                    }
//                                                    ///
//                                                    playblocks[5].remove(height5, width5);
//                                                    solutionBlocks.pop_back();
//                                                }
//                                            }
//                                            ///
//                                            playblocks[4].remove(height4, width4);
//                                            solutionBlocks.pop_back();
//                                        }
//                                    }
//                                    ///
//                                    playblocks[3].remove(height3, width3);
//                                    solutionBlocks.pop_back();
//                                }
//                            }
//                            ///
//                            playblocks[2].remove(height2, width2);
//                            solutionBlocks.pop_back();
//                        }
//                    }
//                    ///
//                    playblocks[1].remove(height1, width1);
//                    solutionBlocks.pop_back();
//                }
//            }
//            playblocks[0].remove(height0, width0);
//            solutionBlocks.pop_back();
//        }
//    }
//    return solvedBoards;
//}
//
//int Solver::calculateDifficulty(Board StartBoard)
//{
//    std::vector<Board> solvedBoards = Solver::solve(StartBoard);
//    m_difficulty = solvedBoards.size();
//    return m_difficulty;
//}

void Solver::setWinningBoard(int **board) {
    for (int col = 0; col < BOARD_HEIGHT; col++) {
        for (int row = 0; row < 8; row++) {
            m_wining_board[col][row] = board[col][row];
        }
    }
}

void Solver::solve(std::optional<int**> board) {
    int** snapshot;
    if(!board.has_value()) snapshot = Board::getBoard();
    else snapshot = board.value();
    for(int rotated = 0; rotated < 2; rotated++)
    {
        for(int y = 0; y < BOARD_HEIGHT; y++)
        {
            for(int x = 0; x < BOARD_WIDTH; x++)
            {
                m_place_try_counter++;

                if(Board::placeBlockSolver(Board::getNotPlacedPlayBlocks()[0], y, x, snapshot,!!rotated))
                {
                    if(Board::getNotPlacedPlayBlocks().empty())
                    {
                        m_win = true;
                        setWinningBoard(snapshot);
                    }
                    else
                    {
                        Board::getNotPlacedPlayBlocks().erase(Board::getNotPlacedPlayBlocks().begin());
                        nextPiece(snapshot);
                        snapshot = board.value();
                    }
                }
            }
        }
    }
}

void Solver::nextPiece(int** board)
{
    m_open_spawns++;
    solve(board);
    m_open_spawns--;
    if(m_open_spawns<1 && !m_win)
    {
        m_is_impossible = true;
    }
}



