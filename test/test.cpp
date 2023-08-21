#include "gtest/gtest.h"
#include "../src/Constants.hpp"
#include "../src/Board/Board.hpp"
#include "../src/Solver/Solver.hpp"

TEST(SolverTests, test_easy_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 2, 1, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 3, 1, BLACK};
    Board::placeBlock(startBlock1, 2,4);
    Board::placeBlock(startBlock2, 3,4);
    Board::placeBlock(startBlock3, 3,3);

    int result = solver.solve(1);
    EXPECT_EQ(result, 1);
}

TEST(SolverTests, test_mdeium_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 2, 1, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 3, 1, BLACK};
    Board::placeBlock(startBlock1, 2,5);
    Board::placeBlock(startBlock2, 2,6);
    Board::placeBlock(startBlock3, 3,5);

    int result = solver.solve(2);
    EXPECT_EQ(result, 2);
}

TEST(SolverTests, test_hard_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    Board::placeBlock(startBlock1, 6,5);
    Board::placeBlock(startBlock2, 6,6);
    Board::placeBlock(startBlock3, 7,5);

    int result = solver.solve(3);
    EXPECT_EQ(result, 3);
}

TEST(SolverTests, test_impossible_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    Board::placeBlock(startBlock1, 0,0);
    Board::placeBlock(startBlock2, 1,1);
    Board::placeBlock(startBlock3, 2,3);

    int result = solver.solve(0);
    EXPECT_EQ(result, 0);
}

