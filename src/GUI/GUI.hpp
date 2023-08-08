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

    void drawBoard();
    void drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks);
    void drawPlacedBlocks(std::vector<Block> placedBlocks);
    int drawStartScreen();
    void drawBackground();
    std::tuple<int, int> calculateCoordinates();

private:
    /* data */
};




#endif