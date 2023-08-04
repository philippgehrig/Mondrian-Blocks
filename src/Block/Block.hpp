//
// Created by Dinar Karchevskii on 04.08.23.
//

#ifndef CPP_EXAM_BLOCK_HPP
#define CPP_EXAM_BLOCK_HPP

/**
 * @brief Block struct
 * @details This struct is used to store information about blocks
 * @param type Type of block
 * @param height Height of block
 * @param width Width of block
 */


enum class BlockType{
    // empty block
    EMPTY = 0,
    //starting blocks
    ONEBYONE = 1,
    ONEBYTWO = 2,
    ONEBYTHREE = 3,

    //play blocks
    TWOBYTWO = 4,
    ONEBYFOUR = 5,
    TWOBYFIVE = 6,
    TWOBYTHREE = 7,
    ONEBYFIVE = 8,
    THREEBYTHREE = 9,
    TWOBYFOUR = 10,
    THREEBYFOUR = 11

};

typedef struct Block
{
    BlockType type;
    int height;
    int width;
} Block;

#endif //CPP_EXAM_BLOCK_HPP
