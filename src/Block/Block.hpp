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
    int getSizeHeight();
    int getSizeWidth();

    void rotate();
    void setSize(int height, int width);

private:
    int m_type;
    int m_size_height;
    int m_size_width;

};


#endif 