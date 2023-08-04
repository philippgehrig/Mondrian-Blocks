#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"
#include "../Block/Block_old.hpp"
#include "../Block/StartBlock/StartBlock.hpp"


class Game
{

public:
    Game(/* args */)
    {};
    ~Game()
    {};

    void start();
    std::vector<Board> init_startblocks();
    std::vector<Block> init_playblocks();


private:
    Board m_board;
    Solver m_solver;
};


#endif 