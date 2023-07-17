#ifndef BLOCK_HPP
#define BLOCK_HPP


class Block
{
public:
    Block(/* args */)
    {};

    ~Block()
    {};

    bool canPlace();

private:
    int m_type;
    bool m_orientation; // 0 == horizontal, 1 == vertical
    int m_size_x;
    int m_size_y;

};


#endif 