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

    static int** getBoard()
    {
        return m_board;
    }

    void setField(int height, int width, int type);


private:
    static int m_board[BOARD_HEIGHT][BOARD_WIDTH];
    std::vector<Block> m_notPlacedBlocks;

};

#endif 