#include "../Board/Board.hpp"

bool Board::isFull()
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            if (m_board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Board::setField(int height, int width, int type) {
    m_board[height][width] = type;
}

void Board::clear_Field() {
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            m_board[i][j] = 0;
        }
    }
}

