#include "Block.hpp"

bool Block::canPlace(int height_coords, int width_coords)
{
    int size_height = m_size_height;
    int size_width = m_size_width;
    int board[BOARD_HEIGHT][BOARD_WIDTH] = Board::getBoard();

    for (int i = height_coords; i < height_coords + size_height; i++)
    {
        for (int j = width_coords; j < width_coords + size_width; j++)
        {
            if (i >= BOARD_HEIGHT || j >= BOARD_WIDTH)
            {
                return false;
            }
            if (board[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int Block::getType()
{
    return m_type;
}

int Block::getSizeHeight()
{
    return m_size_height;
}
int Block::getSizeWidth()
{
    return m_size_width;
}

void Block::setSize(int height, int width)
{
    m_size_height = height;
    m_size_width = width;
}

void Block::setType(int type) {
    m_type = type;
}

