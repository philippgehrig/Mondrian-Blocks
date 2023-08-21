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


    /**
     * @brief starts the Main Menu of the Game
     */
    void play();

    /**
     * @brief starts Mode to build your own Board
     */
    void buildGame();

    /**
     * @brief starts Menu for difficulty Selection
     */
    void difficultySelection();

    /**
     * @brief starts actual Gameplay with placing blocks
     */
    void GamePlay();

    /**
     * @brief opens Menu for little tips
     */
    void showTips();

    /**
     * @brief initialisiert Startblocks
     */
    void initStartblocks();

    /**
     * @brief initialisiert Playblocks
     */
    void initPlayblocks();

    /**
     * @brief generates random StartBlocks on block depending on choosen difficulty
     * @param difficulty difficulty influences how the StartBlocks are placed
     */
    void placeStartblocksGenerate(int difficulty);

    /**
     * @brief Sets solvable Startboards
     * @param difficulty choosen difficulty
     */
     void boardGeneration(int difficulty);



private:
    Board m_board;
    Solver m_solver;
    GUI m_gui;
};


#endif 