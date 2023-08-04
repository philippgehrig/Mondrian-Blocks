#include "StartBlock.hpp"


bool StartBlock::generateRotation()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 1);
    return dis(gen);
}

int StartBlock::generateHeight()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);
    return dis(gen);
}

int StartBlock::generateWidth()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 7);
    return dis(gen);
}

