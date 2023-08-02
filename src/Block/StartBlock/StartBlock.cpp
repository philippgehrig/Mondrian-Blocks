#include "StartBlock.hpp"


bool StartBlock::generateRotation()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    return dis(gen);
}

int StartBlock::generateHeight()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 7);
    return dis(gen);
}

int StartBlock::generateWidth()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 7);
    return dis(gen);
}

