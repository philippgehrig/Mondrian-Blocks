#include "../Game/Game.hpp"

void Game::start()
{

}

void Game::init_startblocks()
{

    StartBlock SBlock0(1, 1, 1);
    StartBlock SBlock1(1, 1, 2);
    StartBlock SBlock2(1, 1, 3);


    std::vector <StartBlock> startblocks {SBlock0, SBlock1, SBlock2};

    int placecheck = 1;

    for (auto it : startblocks)
    {
        // Rotation
        if(it.generateRotation()) // if tru rotate once, if false dont rotate
        {
            it.rotate();
        }

        //platzieren
        do
        {
            placecheck = it.place(it.generateHeight(), it.generateWidth());
        } while(placecheck);
    }

    auto solutions = m_solver.solve(m_board);

    if(!sizeof(solutions)) // if there is no solutions go in this if
    {
        m_board.clear_Field();
        init_startblocks();
    }

}

std::vector<PlayBlock> Game::init_playblocks()
{
    PlayBlock PBlock0(2, 4, 3);
    PlayBlock PBlock1(3, 2, 5);
    PlayBlock PBlock2(4, 3, 3);
    PlayBlock PBlock3(5, 2, 4);
    PlayBlock PBlock4(6, 2, 3);
    PlayBlock PBlock5(7, 1, 5);
    PlayBlock PBlock6(8, 1, 4);
    PlayBlock PBlock7(9, 2, 2);

    std::vector<PlayBlock> playblocks {PBlock0, PBlock1, PBlock2, PBlock3, PBlock4, PBlock5, PBlock6, PBlock7};
    return playblocks;
}
