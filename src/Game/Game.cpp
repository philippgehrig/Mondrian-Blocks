#include "../Game/Game.hpp"

void Game::start()
{
    init_startblocks();
    std::vector<Block> playblocks = init_playblocks();

}

std::vector<Board> Game::init_startblocks()
{

    StartBlock SBlock0(1, 1, 1);
    StartBlock SBlock1(1, 1, 2);
    StartBlock SBlock2(1, 1, 3);


    std::vector <StartBlock> startblocks {SBlock0, SBlock1, SBlock2};

    int placecheck = 1;

    for (auto block : startblocks)
    {
        // Rotation
        if(block.generateRotation()) // if tru rotate once, if false dont rotate
        {
            block.rotate();
        }

        //platzieren
        do
        {
            placecheck = block.place(block.generateHeight(), block.generateWidth());
        } while(placecheck);
    }

    auto solutions = m_solver.solve(m_board);

    if(!sizeof(solutions)) // if there is no solutions go in this if
    {
        m_board.clear_Field();
        init_startblocks();
    }
    else
    {
        return solutions;
    }

}

std::vector<Block> Game::init_playblocks()
{
    Block PBlock0(2, 4, 3);
    Block PBlock1(3, 2, 5);
    Block PBlock2(4, 3, 3);
    Block PBlock3(5, 2, 4);
    Block PBlock4(6, 2, 3);
    Block PBlock5(7, 1, 5);
    Block PBlock6(8, 1, 4);
    Block PBlock7(9, 2, 2);

    std::vector<Block> playblocks {PBlock0, PBlock1, PBlock2, PBlock3, PBlock4, PBlock5, PBlock6, PBlock7};
//    Board::m_notPlacedBlocks = playblocks;
    return playblocks;
}
