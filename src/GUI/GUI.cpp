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

        height *= DRAW_HELP;
        width *= DRAW_HELP;

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
                DrawRectangle(9.5 * DRAW_HELP, 0.5 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(12.5 * DRAW_HELP, 0 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(16 * DRAW_HELP, 0 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(12 * DRAW_HELP, 4.5 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(12.5 * DRAW_HELP, 3.25 * DRAW_HELP, height, width, block.color);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(13.5 * DRAW_HELP, 4.5 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(17 * DRAW_HELP, 4.5 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(9.5 * DRAW_HELP, 3 * DRAW_HELP, width, height, block.color);
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

        height *= DRAW_HELP;
        width *= DRAW_HELP;

        BlockType type = block.type;

        std::optional<std::tuple<int, int>> coordinates = Board::findBlock(block);

        int height_coord = std::get<0>(coordinates.value());
        int width_coord = std::get<1>(coordinates.value());

        switch (type)
        {
            case BlockType::ONEBYONE:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYTWO:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYTHREE:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYTWO:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::THREEBYTHREE:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYTHREE:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYFOUR:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYFIVE:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::THREEBYFOUR:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYFOUR:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::TWOBYFIVE:
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height, block.color);
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
        DrawLine(DRAW_HELP + column * DRAW_HELP, DRAW_HELP, DRAW_HELP + column * DRAW_HELP, 9 * DRAW_HELP, BLACK);
    }
    // horizontal lines
    for(int row = 0; row < BOARD_HEIGHT + 1; row++)
    {
        DrawLine(DRAW_HELP , DRAW_HELP + row * DRAW_HELP, 9 * DRAW_HELP, DRAW_HELP + row * DRAW_HELP, BLACK);
    }
}

std::tuple<int, int> GUI::calculateCoordinates()
{
    Vector2 mousePosition = GetMousePosition();
    int x = mousePosition.x;
    int y = mousePosition.y;

    int height = (y / DRAW_HELP) - 1;
    int width = (x /  DRAW_HELP) - 1;

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
