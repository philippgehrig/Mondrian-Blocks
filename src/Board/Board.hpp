#ifndef BOARD_HPP
#define BOARD_HPP

#include "Game.hpp"
#include "Constants.hpp"
#include "Block.hpp"
#include <vector>

class Board
{
private:
    int m_board[board_height][board_width];
    std::vector<Block> m_notPlacedBlocks;
public:
    bool isFull();
    Board(/* args */);
    ~Board();
};

#endif 