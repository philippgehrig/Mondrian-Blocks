#include "../GUI/GUI.hpp"

void GUI::drawBoard()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawBackground();
    drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());
    drawPlacedBlocks(Board::getPlacedBlocks());
    EndDrawing();
}

void GUI::drawNotPlacedBlocks(std::vector<Block> notPlacedBlocks)
{
    for (auto block : notPlacedBlocks)
    {
        int height = block.height;
        int width = block.width;

        height *= 100;
        width *= 100;

        if(width > height)  //Ensures that height is bigger than width
        {
            int safe = height;
            height = width;
            width = safe;
        }
        BlockType type = block.type;

        switch (type)
        {
            case BlockType::TWOBYTWO:
                DrawRectangle(9.5 * 100, 0.5 * 100, width, height, RED);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(12.5 * 100, 0 * 100, width, height, VIOLET);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(16 * 100, 0 * 100, width, height, GOLD);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(12 * 100, 4.5 * 100, width, height, LIME);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(12.5 * 100, 3.25 * 100, height, width, BLUE);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(13.5 * 100, 4.5 * 100, width, height, DARKBLUE);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(17 * 100, 4.5 * 100, width, height, PINK);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(9.5 * 100, 3 * 100, width, height, YELLOW);
                break;
            default:
                continue;
        }
    }
}

void GUI::drawPlacedBlocks(std::vector<Block> placedBlocks)
{

    for (auto block : placedBlocks)
    {
        int height = block.height;
        int width = block.width;

        height *= 100;
        width *= 100;

        BlockType type = block.type;

        std::optional<std::tuple<int, int>> coordinates = Board::findBlock(block);

        int height_coord = std::get<0>(coordinates.value());
        int width_coord = std::get<1>(coordinates.value());

        switch (type)
        {
            case BlockType::ONEBYONE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, BLACK);
                break;
            case BlockType::ONEBYTWO:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, BLACK);
                break;
            case BlockType::ONEBYTHREE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, BLACK);
                break;
            case BlockType::TWOBYTWO:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, RED);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, VIOLET);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, GOLD);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, LIME);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, BLUE);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, DARKBLUE);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, PINK);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, YELLOW);
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
