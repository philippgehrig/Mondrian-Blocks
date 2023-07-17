#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../Constants.hpp"
#include "../Board/Board.hpp"

class Block
{
public:
    Block(/* args */)
    {};

    ~Block()
    {};

    bool canPlace(int height_coords, int width_coords);


    int getType();
    int getSizeHeight();
    int getSizeWidth();

    void setSize(int height, int width);
    void setType(int type);
    void place(int height, int width);

protected:
    int m_type;
    int m_size_height;
    int m_size_width;

};


#endif 