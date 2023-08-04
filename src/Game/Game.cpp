#include "../Game/Game.hpp"

void Game::start()
{
    init_startblocks();
    std::vector<Block> playblocks = init_playblocks();

}

std::vector<Board> Game::init_startblocks()
{

    Block SBlock0(BlockType::ONEBYONE, 1, 1);
    Block SBlock1(BlockType::ONEBYTWO, 1, 2);
    Block SBlock2(BlockType::ONEBYTHREE, 1, 3);


    std::vector <Block> startblocks {SBlock0, SBlock1, SBlock2};

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

    if(!sizeof(solutions)) // if there is no solutions go in this if
    {
        Board::clearFlied();
        init_startblocks();
    }
    else
    {
        return solutions;
    }

}

std::vector<Block> Game::init_playblocks()
{
    Block PBlock0(BlockType::TWOBYTWO, 2, 2);
    Block PBlock1(BlockType::ONEBYFOUR, 1, 4);
    Block PBlock2(BlockType::TWOBYFIVE, 2, 5);
    Block PBlock3(BlockType::TWOBYTHREE, 2, 3);
    Block PBlock4(BlockType::ONEBYFIVE, 1, 5);
    Block PBlock5(BlockType::THREEBYTHREE, 3, 3);
    Block PBlock6(BlockType::TWOBYFOUR, 2, 4);
    Block PBlock7(BlockType::THREEBYFOUR, 3, 4);

    std::vector<Block> playblocks {PBlock0, PBlock1, PBlock2, PBlock3, PBlock4, PBlock5, PBlock6, PBlock7};
    return playblocks;
}
