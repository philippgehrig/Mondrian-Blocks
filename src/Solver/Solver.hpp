#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../Board/Board.hpp"
#include <vector>

class Solver
{
public:
    Solver(/* args */)
    {};
    ~Solver()
    {};

    std::vector<Board> solve(Board StartBoard);
    int calculateDifficulty(Board StartBoard);


private:
    int m_difficulty;

};


#endif