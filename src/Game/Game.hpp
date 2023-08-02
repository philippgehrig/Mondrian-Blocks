#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"
#include "../Block/Block.hpp"
#include "../Block/StartBlock/StartBlock.hpp"


class Game
{

public:
    Game(/* args */)
    {};
    ~Game()
    {};

    void start();
    void init_startblocks();


private:
    Board m_board;
    Solver m_solver;
};


#endif 