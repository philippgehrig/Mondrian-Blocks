#ifndef PLAYBLOCK_HPP
#define PLAYBLOCK_CPP
#include "Block.hpp"

class PlayBlock : public Block
{
private:
    /* data */
public:
    void rotate();
    void remove();
    void place();
    PlayBlock(/* args */);
    ~PlayBlock();
};



#endif