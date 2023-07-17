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

    bool getOrientation();
    int getType();
    int getSize();

private:
    int m_type;
    bool m_orientation; // 0 == horizontal, 1 == vertical
    int m_size[2];

};


#endif 