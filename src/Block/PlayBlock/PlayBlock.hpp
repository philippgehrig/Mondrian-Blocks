#ifndef PLAYBLOCK_HPP
#define PLAYBLOCK_HPP

#include "../Block.hpp"

class PlayBlock : public Block
{
public:
    PlayBlock(/* args */)
    {};
    ~PlayBlock()
    {};

    void rotate();
    void remove();
    void place(int height, int width);


private:
    /* data */

};



#endif