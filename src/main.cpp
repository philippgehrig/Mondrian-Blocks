#include <iostream>
#include "Game/Game.hpp"
#include "Solver/Solver.hpp"


int main()
{
//    Game game;
    //game.GamePlay();
//    game.play();

    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    Board::placeBlock(startBlock1, 0,0);
    Board::placeBlock(startBlock2, 0,1);
    Board::placeBlock(startBlock3, 0,3);
    Solver solver;
    solver.solve();
    solver.printStatus();
    int** board = solver.getWinningBoard();

    for(int column = 0; column < BOARD_HEIGHT; column++)
    {
        for(int row = 0; row < BOARD_WIDTH; row++)
        {
            if(board[column][row] < 10) std::cout << " ";
            std::cout << board[column][row] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
