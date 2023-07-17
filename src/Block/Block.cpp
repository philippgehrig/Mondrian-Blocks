#include "Block.hpp"

bool Block::canPlace()
{
}

bool Block::getOrientation()
{
    return m_orientation;
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

void Block::rotate()
{
    int tmp;
    tmp = m_size_height;
    m_size_height = m_size_width;
    m_size_width = tmp;
}

void Block::setSize(int height, int width)
{
    m_size_height = height;
    m_size_width = width;
}

