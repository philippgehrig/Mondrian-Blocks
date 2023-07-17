#ifndef BOARD_HPP
#define BOARD_HPP

#include "../Constants.hpp"
#include "../Block/Block.hpp"
#include <vector>

class Board
{
public:
    Board(/* args */){};
    ~Board(){};

    bool isFull();

    int getBoard();


private:
    int m_board[BOARD_HEIGHT][BOARD_WIDTH];
    std::vector<Block> m_notPlacedBlocks;

};

#endif 