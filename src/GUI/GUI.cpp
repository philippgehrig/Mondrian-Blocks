#include "../GUI/GUI.hpp"

void GUI::drawBoard()
{
    int** board = Board::getBoard();
    for (int column = 0; column < BOARD_HEIGHT; column++) {
        for (int row = 0; row < BOARD_WIDTH; row++) {
            std::cout << board[column][row] << " ";
        }
        std::cout << std::endl;
    }
}

void GUI::drawNotPlacedBlocks()
{
    std::vector<Block> notPlacedBlocks = Board::getNotPlacedBlocks();
    for (auto block : notPlacedBlocks)
    {
        std::cout << " " << std::endl;
    }
}

void GUI::drawStartScreen()
{
}

