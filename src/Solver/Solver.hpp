#ifndef SOLVER_HPP
#define SOLVER_CPP

#include <vector>
#include "Board.hpp"
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