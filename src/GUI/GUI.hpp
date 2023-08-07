#ifndef GUI_HPP
#define GUI_HPP

#include "../Solver/Solver.hpp"
#include "../Board/Board.hpp"
#include "../Constants.hpp"
#include <iostream>
#include <optional>
#include "raylib.h"

class GUI
{

public:
    GUI(/* args */){};
    ~GUI(){};

    void drawBoard(Board board);
    void drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks);
    void drawPlacedBlocks(std::vector<Block> placedBlocks);
    void drawStartScreen();
    void drawBackground();
    std::tuple<int, int> calculateCoordinates();

private:
    /* data */
};




#endif