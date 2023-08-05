#include "../GUI/GUI.hpp"

void GUI::drawBoard(Board board)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawBackground();
    drawNotPlacedBlocks(board.getNotPlacedPlayBlocks());
    drawPlacedBlocks(board.getPlacedBlocks());
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
        int height = block.height;
        int width = block.width;
        BlockType type = block.type;

        switch (type)
        {
            case BlockType::ONEBYONE:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, BLACK);
                break;
            case BlockType::ONEBYTWO:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, BLACK);
                break;
            case BlockType::ONEBYTHREE:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, BLACK);
                break;
            case BlockType::TWOBYTWO:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, RED);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, VIOLET);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, GOLD);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, LIME);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, BLUE);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, DARKBLUE);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, PINK);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(100 + width * 100, 100 + height * 100, width, height, YELLOW);
                break;
            default:
                continue;
        }
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
