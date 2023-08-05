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

    }
}

void GUI::drawPlacedBlocks(std::vector<Block> placedBlocks)
{
    for (auto block : placedBlocks)
    {

    }
}

void GUI::drawStartScreen()
{
}

void GUI::drawBackground()
{
    // vertical lines
    for(int column = 0; column < BOARD_WIDTH + 1; column++)
    {
        DrawLine(100 + column * 100, 100, 100 + column * 100, 900, BLACK);
    }
    // horizontal lines
    for(int row = 0; row < BOARD_HEIGHT + 1; row++)
    {
        DrawLine(100 , 100 + row * 100, 900, 100 + row * 100, BLACK);
    }
}

std::tuple<int, int> GUI::calculateCoordinates()
{
    Vector2 mousePosition = GetMousePosition();
    int x = mousePosition.x;
    int y = mousePosition.y;

    int height = (y % 100) + 1;
    int width = (x % 100) + 1;

    return std::make_tuple(height, width);
}
