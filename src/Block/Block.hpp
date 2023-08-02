#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../Constants.hpp"
#include "../Board/Board.hpp"

class Block
{
public:
    Block(int type, int size_height, int size_width)
    : m_type(type)
    , m_size_height(size_height)
    , m_size_width(size_width)
    {};

    ~Block()
    {};

    bool canPlace(int height_coords, int width_coords);


    int getType();
    int getSizeHeight();
    int getSizeWidth();

    void rotate();
    void setSize(int height, int width);
    void setType(int type);
    int place(int height_coordinate, int width_coordinate);

protected:
    int m_type;
    int m_size_height;
    int m_size_width;

};


#endif 