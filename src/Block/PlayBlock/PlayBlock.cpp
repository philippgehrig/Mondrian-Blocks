#include "PlayBlock.hpp"

void PlayBlock::remove(int height, int width)
{
    int size_height = m_size_height;
    int size_width = m_size_width;
    int board[BOARD_HEIGHT][BOARD_WIDTH] = Board::getBoard();

    for (int i = height; i < height + size_height; i++)
    {
        for (int j = width; j < width + size_width; j++)
        {
            Board::setField(i, j, 0);
        }
    }
}

void PlayBlock::rotate()
{
    int tmp = m_size_height;
    m_size_height = m_size_width;
    m_size_width = tmp;
}

