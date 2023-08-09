#include "../GUI/GUI.hpp"

void GUI::drawBoard()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGameBackground();
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
                DrawRectangle(9.5 * 100, 0.5 * 100, width, height, block.color);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(12.5 * 100, 0 * 100, width, height, block.color);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(16 * 100, 0 * 100, width, height, block.color);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(12 * 100, 4.5 * 100, width, height, block.color);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(12.5 * 100, 3.25 * 100, height, width, block.color);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(13.5 * 100, 4.5 * 100, width, height, block.color);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(17 * 100, 4.5 * 100, width, height, block.color);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(9.5 * 100, 3 * 100, width, height, block.color);
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
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::ONEBYTWO:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::ONEBYTHREE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::TWOBYTWO:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(100 + width_coord * 100, 100 + height_coord * 100, width, height, block.color);
                break;
            default:
                continue;
        }
    }
}

int GUI::drawStartScreen()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Welcome to Mondrian Blocks", 100, 100, 20, BLACK);
    DrawText("Press 1 to start the game", 100, 200, 20, BLACK);
    DrawText("Press 2 to start a game with your own borad", 100, 300, 20, BLACK);
    DrawText("Press 3 to acces the Solver", 100, 400, 20, BLACK);
    EndDrawing();

    while(true)
    {
        if(IsKeyPressed(KEY_ONE))
        {
            return 1;
        }
        else if(IsKeyPressed(KEY_TWO))
        {
            return 2;
        }
        else if(IsKeyPressed(KEY_THREE))
        {
            return 3;
        }
    }
}

void GUI::drawGameBackground()
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

    int height = (y / 100) - 1;
    int width = (x /  100) - 1;

    return std::make_tuple(height, width);
}

void GUI::drawBlockAtMouse(BlockType type)
{
    auto coordinates = calculateCoordinates();
    int height_coord = std::get<0>(coordinates);
    int width_coord = std::get<1>(coordinates);

    Block block = findBlockFromType(type);

    int height = block.height;
    int width = block.width;

    Color color = block.color;

    BeginDrawing();
    DrawRectangle(width_coord, height_coord, width, height, color);
    EndDrawing();
}

BlockType GUI::isMouseOnBlock()
{
    // check on field
    auto coordinates = calculateCoordinates();
    int height_coord = std::get<0>(coordinates);
    int width_coord = std::get<1>(coordinates);

    for(auto block : Board::getPlacedBlocks())
    {
        if(block.height == height_coord && block.width == width_coord)
        {
            return block.type;
        }
    }


    // check for outside of field
    Vector2 mousePosition = GetMousePosition();
    int x_coord = mousePosition.x;
    int y_coord = mousePosition.y;

}

Block GUI::findBlockFromType(BlockType type)
{

    for(auto block :  Board::getAllBlocks())
    {
        if(block.type == type)
        {
            return block;
        }
    }
}
