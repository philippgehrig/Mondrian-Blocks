#include "../Game/Game.hpp"

void Game::start()
{

}

void Game::init_startblocks()
{

    StartBlock SBlock0(0, 1, 1);
    StartBlock SBlock1(1, 1, 2);
    StartBlock SBlock2(2, 1, 3);


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

