#include "Solver.hpp"

std::vector<Board> Solver::solve(Board StartBoard)
{
    std::vector<Board> solvedBoards;


    return solvedBoards;
}

int Solver::calculateDifficulty(Board StartBoard)
{
    std::vector<Board> solvedBoards = Solver::solve(StartBoard);
    m_difficulty = solvedBoards.size();
    return m_difficulty;
}



