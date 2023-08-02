#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"
#include "../Block/Block.hpp"
#include "../Block/StartBlock/StartBlock.hpp"
#include "../Block/PlayBlock/PlayBlock.hpp"


class Game
{

public:
    Game(/* args */)
    {};
    ~Game()
    {};

    void start();
    void init_startblocks();
    std::vector<PlayBlock> init_playblocks();


private:
    Board m_board;
    Solver m_solver;
};


#endif 