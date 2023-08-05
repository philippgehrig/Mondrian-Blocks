#include "../GUI/GUI.hpp"

void GUI::drawBoard(Board board)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    drawBackground();
}

void GUI::drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks)
{
    for (auto block : notPlacedBlocks)
    {
        std::cout << " " << std::endl;
    }
}

void GUI::drawStartScreen()
{
}

void GUI::drawBackground()
{
    // optimize in one loop? => runtime optimization
    for(int column = 0; column < BOARD_WIDTH + 1; column++)
    {
        DrawLine(100 + column * 100, 100, 900 + column * 100, 900, BLACK);
    }
    for(int row = 0; row < BOARD_HEIGHT + 1; row++)
    {
        DrawLine(100 , 100 + row * 100, 900, 900 + row * 100, BLACK);
    }
}
