#include "../Game/Game.hpp"

void Game::start()
{
    std::vector<Block> startblocks = initStartblocks();
    std::vector<Board> solutions = placeStartblocks(startblocks);
    std::vector<Block> playblocks = initPlayblocks();
}

std::vector<Block> Game::initStartblocks()
{
    Block SBlock0(BlockType::ONEBYONE, 1, 1);
    Block SBlock1(BlockType::ONEBYTWO, 1, 2);
    Block SBlock2(BlockType::ONEBYTHREE, 1, 3);
    std::vector <Block> startblocks {SBlock0, SBlock1, SBlock2};

    return startblocks;
}

std::vector<Board> Game::placeStartblocks(std::vector<Block> startblocks)
{

    int placecheck = 1;

    for (auto block : startblocks)
    {
        // Rotation
        if(Board::generateRotation()) // if tru rotate once, if false dont rotate
        {
            Board::rotateBlock(block);
        }

        //platzieren
        do
        {
            placecheck = Board::placeBlock(block, Board::generateCoordinate(), Board::generateCoordinate()); // generate functions??
        } while(placecheck);
    }

    auto solutions = m_solver.solve(m_board);

    int number_of_solutions = solutions.size();
    if(!number_of_solutions) // if there is no solutions go in this if
    {
        Board::clearFlied();
        placeStartblocks(startblocks);
    }
    else
    {
        return solutions;
    }

}

std::vector<Block> Game::initPlayblocks() {
    Block PBlock2x2(BlockType::TWOBYTWO, 2, 2);
    Block PBlock1x4(BlockType::ONEBYFOUR, 1, 4);
    Block PBlock2x5(BlockType::TWOBYFIVE, 2, 5);
    Block PBlock2x3(BlockType::TWOBYTHREE, 2, 3);
    Block PBlock1x5(BlockType::ONEBYFIVE, 1, 5);
    Block PBlock3x3(BlockType::THREEBYTHREE, 3, 3);
    Block PBlock2x4(BlockType::TWOBYFOUR, 2, 4);
    Block PBlock3x4(BlockType::THREEBYFOUR, 3, 4);

    std::vector<Block> playblocks {PBlock3x4, PBlock2x5, PBlock3x3, PBlock2x4, PBlock2x3, PBlock1x5, PBlock1x4, PBlock2x2};
    return playblocks;
}
