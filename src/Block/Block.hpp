#ifndef BLOCK_HPP
#define BLOCK_HPP


class Block
{
private:
    int m_type;
    bool m_orientation;
    int m_size_x;
    int m_size_y;
public:
    bool canPlace();
    Block(/* args */);
    ~Block();
};


#endif 