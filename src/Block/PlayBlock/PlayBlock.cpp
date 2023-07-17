#include "PlayBlock.hpp"

void PlayBlock::remove() //add to m_notPlacedBlocks
{
}

void PlayBlock::place()  //remove form m_notPlacedBlocks
{
}

void PlayBlock::rotate()
{
    int tmp;
    tmp = m_size_height;
    m_size_height = m_size_width;
    m_size_width = tmp;
}

