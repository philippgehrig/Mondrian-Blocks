#ifndef GUI_HPP
#define GUI_HPP

#include "../Solver/Solver.hpp"

class GUI
{
private:
    /* data */
public:
    void drawBoard();
    void drawNotPlacedBlocks();
    void drawStartScreen();
    GUI(/* args */);
    ~GUI();
};




#endif