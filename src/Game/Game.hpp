#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"
#include "../Block/Block_old.hpp"



class Game
{

public:
    Game(/* args */)
    {};
    ~Game()
    {};

    void start();
    std::vector<Block> initStartblocks();
    std::vector<Board> placeStartblocks(std::vector<Block> startblocks);
    std::vector<Block> initPlayblocks();


private:
    Board m_board;
    Solver m_solver;
};


#endif 