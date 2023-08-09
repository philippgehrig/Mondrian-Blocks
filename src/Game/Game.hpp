#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>

#include "../Board/Board.hpp"
#include "../Solver/Solver.hpp"
#include "../GUI/GUI.hpp"
#include "raylib.h"


class Game
{

public:
    Game(/* args */)
    {};
    ~Game()
    {};

    void start();
    void initStartblocks();
    void initPlayblocks();
    void playGame();
    void solveGame();
    void placeOwnStartblocks();
    void debug();
    std::vector<Board> placeStartblocksGenerate();

    void GUItest();



private:
    Board m_board;
    Solver m_solver;
    GUI m_gui;
};


#endif 