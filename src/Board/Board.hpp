#ifndef BOARD_HPP
#define BOARD_HPP

#include "../Constants.hpp"
#include "../Block/Block.hpp"
#include <vector>

class Board
{
public:
    Board()
    {};
    ~Board(){};

    static bool isFull();

    static int** getBoard()
    {
        return m_board;
    }

    static void setField(int height, int width, int type);
    void clear_Field();
    void setBoard(std::vector <Block> blocks);

    static std::vector<Block> m_notPlacedBlocks;
private:
    static int m_board[BOARD_HEIGHT][BOARD_WIDTH];


};

#endif 