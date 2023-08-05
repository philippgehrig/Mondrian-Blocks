#ifndef GUI_HPP
#define GUI_HPP

#include "../Solver/Solver.hpp"
#include "../Board/Board.hpp"
#include "../Constants.hpp"
#include "../../raylib-master/src/raylib.h"


class GUI
{

public:
    GUI(/* args */){};
    ~GUI(){};

    void drawBoard(Board board);
    void drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks);
    void drawStartScreen();
    void drawBackground();

private:
    /* data */
};




#endif