#ifndef BOARD_HPP
#define BOARD_HPP

#include "Game.hpp"
#include "Constants.hpp"

class Board
{
private:
    int m_board[board_height][board_width];
public:
    bool isFull();
    Board(/* args */);
    ~Board();
};

#endif 