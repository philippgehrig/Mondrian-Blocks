#ifndef GAME_HPP
#define GAME_HPP

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"
class Game
{
private:
    Board m_board;
    Solver m_solver;
public:
    void start();
    Game(/* args */);
    ~Game();
};


#endif 