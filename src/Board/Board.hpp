#ifndef BOARD_HPP
#define BOARD_HPP

#include "../Constants.hpp"
//#include "../Block/Block.hpp"
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
        // You can create a new 2D array and copy the values of m_board to it
        int** boardCopy = new int*[BOARD_HEIGHT];
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            boardCopy[i] = new int[BOARD_WIDTH];
            for (int j = 0; j < BOARD_WIDTH; j++) {
                boardCopy[i][j] = m_board[i][j];
            }
        }

        return boardCopy;
    }


    static void setField(int height, int width, int type);
    void clear_Field();
//    void setBoard(std::vector<Block> blocks);

//    static std::vector<Block> m_notPlacedBlocks;
private:
    static int m_board[BOARD_HEIGHT][BOARD_WIDTH];


};

#endif 