#ifndef GAME_HPP
#define GAME_HPP

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"

class Game
{

public:
    Game(/* args */)
    {};
    ~Game()
    {};

    void start();


private:
    Board m_board;
    Solver m_solver;
};


#endif 