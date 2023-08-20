#include "gtest/gtest.h"
#include "../src/Constants.hpp"
#include "../src/Board/Board.hpp"
#include "../src/Solver/Solver.hpp"
#include "../src/Game/Game.hpp"
#include "../src/GUI/GUI.hpp"

TEST(SolverTests, test_easy_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    Board::placeBlock(startBlock1, 0,0);
    Board::placeBlock(startBlock2, 0,1);
    Board::placeBlock(startBlock3, 0,3);

    int result = solver.solve();
    EXPECT_EQ(result, 1);
}

TEST(SolverTests, test_mdeium_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    Board::placeBlock(startBlock1, 0,0);
    Board::placeBlock(startBlock2, 0,1);
    Board::placeBlock(startBlock3, 0,3);

    int result = solver.solve();
    EXPECT_EQ(result, 1);
}

TEST(SolverTests, test_hard_board)
{
    Board board;
    Solver solver;

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    Board::placeBlock(startBlock1, 0,0);
    Board::placeBlock(startBlock2, 0,1);
    Board::placeBlock(startBlock3, 0,3);

    int result = solver.solve();
    EXPECT_EQ(result, 1);
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

    int result = solver.solve();
    EXPECT_EQ(result, 0);
}

