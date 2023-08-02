#include "Solver.hpp"

std::vector<Board> Solver::solve(Board StartBoard)
{
    std::vector<Board> solvedBoards;
    std::vector<Block> playblocks = Board::m_notPlacedBlocks;

    // Dummer Btute-Force Ansatz:

    int check[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for( auto it : playblocks)
    {
        for(int height1; height1 < 8; height1++)
        {
            if(!check[1]) break;
            for(int width1; width1 < 8; width1++)
            {
                check[1] = it.place(height1, width1);
                if(!check[1]) it.rotate();
                if(!check[1])
                {
                    StartBoard.remove(it);
                    break;
                }
            }
        }
    }


    return solvedBoards;
}

int Solver::calculateDifficulty(Board StartBoard)
{
    std::vector<Board> solvedBoards = Solver::solve(StartBoard);
    m_difficulty = solvedBoards.size();
    return m_difficulty;
}



