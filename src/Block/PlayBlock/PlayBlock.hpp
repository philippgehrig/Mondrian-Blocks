#ifndef PLAYBLOCK_HPP
<<<<<<< HEAD
#define PLAYBLOCK_CPP
#include "../Block/Block.hpp"
=======
#define PLAYBLOCK_HPP

#include "../Block.hpp"
>>>>>>> 2934db9 (Added CMakeLists to test. Added test.cpp to test. Refactored links and structure.)

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