#ifndef GUI_HPP
#define GUI_HPP

#include "../Solver/Solver.hpp"
#include "../Board/Board.hpp"
#include "../Constants.hpp"
#include <iostream>
#include <optional>
#include "raylib.h"
#include <tuple>

class GUI
{

public:
    GUI(/* args */){};
    ~GUI(){};

    /**
     * @brief draws every not placed Block
     * @param notPlacedBlocks: vector of not placed Blocks
     */
    void drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks);

    /**
     * @brief draws every not placed Start Block
     * @param notPlacedStartBlocks: vector of not placed Start Blocks
     */
    void drawNotPlacedStartBlocks(std::vector<Block> notPlacedStartBlocks);

    /**
     * @brief draws every placed Block
     * @param placedBlocks: vector of placed Blocks
     */
    void drawPlacedBlocks(std::vector<Block> placedBlocks);

    /**
     * @brief draws the Start Screen
     * @return the mode you choose
     */
    int drawStartScreen();

    /**
     * @brief draws the Backgorund of the Game
     */
    void drawGameBackground();

    /**
     * @brief Draws the Block with mouse Movement
     * @param type: declares type of  Block which is moved
     */
    void drawBlockAtMouse(BlockType type);

    /**
     * @brief transfers mouse coordinates into Board coordinates
     * @return Board coordinates
     */
    std::tuple<int, int> calculateMouseCoordinates();

    /**
     * @brief finds Block with the type given
     * @param type: given type
     * @return the Block with the given Type
     */
    Block findBlockFromType(BlockType type);

    /**
     * @brief draws Win Screen
     * @return choose new gamemode
     */
    int drawWinScreen();

    /**
     * @brief draws Menu for difficulty Selection
     * @return integer for Difficultyselection
     */
    int drawDifficultySelection();

     /**
      * @brief checks if mouse is on a Block
      * @return block Type
      */
     BlockType isMouseOnStartBlock();

    /**
      * @brief checks if mouse is on a Block
      * @return block Type
      */
     BlockType isMouseOnBlock();







private:
    /* data */
};




#endif