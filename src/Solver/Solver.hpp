#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../Board/Board.hpp"
#include <vector>

class Solver
{
private:
    /* data */
public:
    std::vector<Board> solve(Board StartBoard);
    int calculateDifficulty();
    Solver(/* args */);
    ~Solver();
};


#endif