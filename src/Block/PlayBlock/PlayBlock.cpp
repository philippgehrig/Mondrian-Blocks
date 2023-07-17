#include "PlayBlock.hpp"

void PlayBlock::remove() //add to m_notPlacedBlocks
{
}

void PlayBlock::place(int height, int width)  //remove form m_notPlacedBlocks
{
    if(Block::canPlace(height, width))
    {
        int size_height = m_size_height;
        int size_width = m_size_width;
        int board[BOARD_HEIGHT][BOARD_WIDTH] = Board::getBoard();

        for (int i = height; i < height + size_height; i++)
        {
            for (int j = width; j < width + size_width; j++)
            {
                Board::setField(i, j, m_type);
            }
        }

    }


}

void PlayBlock::rotate()
{
    int tmp;
    tmp = m_size_height;
    m_size_height = m_size_width;
    m_size_width = tmp;
}

