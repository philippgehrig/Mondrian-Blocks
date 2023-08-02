#ifndef STARTBLOCK_HPP
#include "../Block.hpp"
#include <random>

class StartBlock : public Block
{
public:

    StartBlock(int type, int size_height, int size_width)
    : Block(type, size_height, size_width)
    {};
    ~StartBlock()
    {};

    bool generateRotation();
    int generateHeight();
    int generateWidth();

private:
    /* data */

};



#endif