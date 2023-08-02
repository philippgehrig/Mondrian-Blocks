#ifndef PLAYBLOCK_HPP
#define PLAYBLOCK_HPP

#include "../Block.hpp"

class PlayBlock : public Block
{
public:
    PlayBlock(int type, int sizeHeight, int sizeWidth)
    : Block(type, sizeHeight, sizeWidth) {};
    ~PlayBlock()
    {};


    void remove(int height, int width);


private:
    /* data */

};



#endif