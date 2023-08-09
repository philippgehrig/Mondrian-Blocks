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
     * @brief starts every draw function to game
     */
    void drawBoard();

    /**
     * @brief draws every not placed Block
     */
    void drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks);

    /**
     * @brief draws every placed Block
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
     */
    void drawBlockAtMouse(BlockType type);

    /**
     * @brief Drag and Drop function
     */
    void drackAndDrop();

    /**
     * @brief transfers mouse coordinates into Board coordinates
     * @return Board coordinates
     */
    std::tuple<int, int> calculateMouseCoordinates();

    /**
     * @brief checks if mouse is on a Block
     * @return block Type
     */
    BlockType isMouseOnBlock();

    /**
     * @brief finds Block with the type given
     * @return the Block with the given Type
     */
    Block findBlockFromType(BlockType type);


private:
    /* data */
};




#endif