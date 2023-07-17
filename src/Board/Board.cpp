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

void Board::setBoard(Board Board) {
    m_board = Board;
}

