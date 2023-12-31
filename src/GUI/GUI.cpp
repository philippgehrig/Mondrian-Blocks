#include "../GUI/GUI.hpp"
#include <iostream>


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
                DrawRectangle(12 * DRAW_HELP, 4.5 * DRAW_HELP, width, height,block.color);
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

void GUI::drawNotPlacedStartBlocks(std::vector<Block> notPlacedStartBlocks)
{
    for (auto block : notPlacedStartBlocks)
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
            case BlockType::ONEBYONE:
                DrawRectangle(10 * DRAW_HELP, 1 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYTWO:
                DrawRectangle(12 * DRAW_HELP, 1 * DRAW_HELP, width, height, block.color);
                break;
            case BlockType::ONEBYTHREE:
                DrawRectangle(14 * DRAW_HELP, 1 * DRAW_HELP, width, height, block.color);
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
                DrawRectangle(DRAW_HELP + width_coord * DRAW_HELP, DRAW_HELP + height_coord * DRAW_HELP, width, height,block.color);
                break;
            default:
                continue;
        }
    }
}

int GUI::drawStartScreen()
{

    //while(true)
    {
        DrawText("Welcome to Mondrian Blocks", 100, 100, 20, BLACK);
        DrawText("Press 1 to start the game", 100, 200, 20, BLACK);
        DrawText("Press 2 to start a game with your own board", 100, 300, 20, BLACK);
        DrawText("Press 3 to show some Tips", 100, 400, 20, BLACK);


        if(IsKeyPressed(KEY_ONE))
        {
            return 1;
        }
        else if(IsKeyPressed(KEY_TWO))
        {
            return 2;
        }else if(IsKeyPressed(KEY_THREE))
        {
            return 3;
        }


        return -1;
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

std::tuple<int, int> GUI::calculateMouseCoordinates()
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
    Vector2 mousePosition = GetMousePosition();

    int height_coord = mousePosition.y;
    int width_coord = mousePosition.x;

    Block block = findBlockFromType(type);

    int height = block.height;
    int width = block.width;

    Color color = block.color;

    //BeginDrawing();
    DrawRectangle(width_coord, height_coord, width * DRAW_HELP, height * DRAW_HELP, color);
    //EndDrawing();
}

BlockType GUI::isMouseOnBlock()
{
    // check on field
    auto coordinates = calculateMouseCoordinates();
    int height_coord = std::get<0>(coordinates);
    int width_coord = std::get<1>(coordinates);

    int height_coord_block = 0;
    int width_coord_block = 0;
    for(auto block : Board::getPlacedBlocks())
    {
        std::optional<std::tuple<int, int>> coordinates = Board::findBlock(block);

        height_coord_block = std::get<0>(coordinates.value());
        width_coord_block = std::get<1>(coordinates.value());
        if(height_coord == height_coord_block && width_coord == width_coord_block)
        {
            return block.type;
        }
    }


    // check for outside of field
    Vector2 mousePosition = GetMousePosition();
    height_coord = mousePosition.y;
    width_coord = mousePosition.x;

    //Money is awesome
    std::vector<BlockType> possibilities;
    for(auto block : Board::getNotPlacedPlayBlocks())
    {
        possibilities.push_back(block.type);
    }
    
    if(((width_coord > (9.5 * DRAW_HELP)) && (width_coord < ((9.5 + 2) * DRAW_HELP)))
    && ((height_coord > (0.5 * DRAW_HELP)) && (height_coord < ((0.5 + 2) * DRAW_HELP))))
    {
        return BlockType::TWOBYTWO;
    }

    if(((width_coord > (12.5 * DRAW_HELP))&& (width_coord < ((12.5 + 3) * DRAW_HELP)))
    && ((height_coord > (0 * DRAW_HELP)) && (height_coord < ((0 + 3) * DRAW_HELP))))
    {
        return BlockType::THREEBYTHREE;
    }

    if(((width_coord > (16 * DRAW_HELP)) && (width_coord < ((16 + 2) * DRAW_HELP)))
    && ((height_coord > (0 * DRAW_HELP)) && (height_coord < ((0 + 3) * DRAW_HELP))))
    {
        return BlockType::TWOBYTHREE;
    }

    if(((width_coord > (12 * DRAW_HELP)) && (width_coord < ((12 + 1) * DRAW_HELP)))
    && ((height_coord > (4.5 * DRAW_HELP)) && (height_coord < ((4.5 + 4) * DRAW_HELP))))
    {
        return BlockType::ONEBYFOUR;
    }

    if(((width_coord > (12.5 * DRAW_HELP)) && (width_coord < ((12.5 + 5) * DRAW_HELP)))
    && ((height_coord > (3.25 * DRAW_HELP)) && (height_coord < ((3.25 + 1) * DRAW_HELP))))
    {
        return BlockType::ONEBYFIVE;
    }

    if(((width_coord > (12 * DRAW_HELP)) && (width_coord < ((12 + 1) * DRAW_HELP)))
       && ((height_coord > (4.5 * DRAW_HELP)) && (height_coord < ((4.5 + 4) * DRAW_HELP))))
    {
        return BlockType::ONEBYFOUR;
    }

    if(((width_coord > (13.5 * DRAW_HELP)) && (width_coord < ((13.5 + 3) * DRAW_HELP)))
       && ((height_coord > (4.5 * DRAW_HELP)) && (height_coord < ((4.5 + 4) * DRAW_HELP))))
    {
        return BlockType::THREEBYFOUR;
    }

    if(((width_coord > (17 * DRAW_HELP)) && (width_coord < ((17 + 2) * DRAW_HELP)))
       && ((height_coord > (4.5 * DRAW_HELP)) && (height_coord < ((4.5 + 4) * DRAW_HELP))))
    {
        return BlockType::TWOBYFOUR;
    }

    if(((width_coord > (9.5 * DRAW_HELP)) && (width_coord < ((9.5 + 2) * DRAW_HELP)))
       && ((height_coord > (3 * DRAW_HELP)) && (height_coord < ((3 + 5) * DRAW_HELP))))
    {
        return BlockType::TWOBYFIVE;
    }

    return BlockType::NONE;
}

Block GUI::findBlockFromType(BlockType type)
{
    auto blocks = Board::getAllBlocks();
    for(auto block : blocks)
    {
        if(block.type == type)
        {
            return block;
        }
    }
}

int GUI::drawWinScreen()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("You won!", 20, 20, 40, BLACK);
        EndDrawing();
    }

}

BlockType GUI::isMouseOnStartBlock()
{
    // check on field
    auto coordinates = calculateMouseCoordinates();
    int height_coord = std::get<0>(coordinates);
    int width_coord = std::get<1>(coordinates);

    int height_coord_block = 0;
    int width_coord_block = 0;
    for(auto block : Board::getPlacedBlocks())
    {
        std::optional<std::tuple<int, int>> coordinates = Board::findBlock(block);

        height_coord_block = std::get<0>(coordinates.value());
        width_coord_block = std::get<1>(coordinates.value());
        if(height_coord == height_coord_block && width_coord == width_coord_block)
        {
            return block.type;
        }
    }


    // check for outside of field
    Vector2 mousePosition = GetMousePosition();
    height_coord = mousePosition.y;
    width_coord = mousePosition.x;

    if(((width_coord > (10 * DRAW_HELP)) && (width_coord < ((10 + 1) * DRAW_HELP)))
       && ((height_coord > (1 * DRAW_HELP)) && (height_coord < ((1 + 1) * DRAW_HELP))))
    {
        return BlockType::ONEBYONE;
    }

    if(((width_coord > (12 * DRAW_HELP))&& (width_coord < ((12 + 1) * DRAW_HELP)))
       && ((height_coord > (1 * DRAW_HELP)) && (height_coord < ((1 + 2) * DRAW_HELP))))
    {
        return BlockType::ONEBYTWO;
    }

    if(((width_coord > (14 * DRAW_HELP)) && (width_coord < ((14 + 1) * DRAW_HELP)))
       && ((height_coord > (1 * DRAW_HELP)) && (height_coord < ((1 + 3) * DRAW_HELP))))
    {
        return BlockType::ONEBYTHREE;
    }



    return BlockType::NONE;
}

int GUI::drawDifficultySelection()
{
    DrawText("Choose Difficulty", 100, 100, 20, BLACK);
    DrawText("Press 1 for easy", 100, 200, 20, BLACK);
    DrawText("Press 2 for medium", 100, 300, 20, BLACK);
    DrawText("Press 3 for hard", 100, 400, 20, BLACK);

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

void GUI::drawShowTips()
{
    DrawText("Little Tips", 100, 100, 20, BLACK);
    DrawText("Press R to rotate Block", 100, 200, 20, BLACK);
    DrawText("Press S in build Menu to start playing", 100, 300, 20, BLACK);
    DrawText("The Solver does take some Time but if you wait more than a minute its unsolvable", 100, 400, 20, BLACK);
}

void GUI::drawSolverButton()
{
    DrawRectangle(2.8 * DRAW_HELP, 9.2 * DRAW_HELP, 4 * DRAW_HELP, 0.5 * DRAW_HELP, GOLD);
    DrawText("Solver Button", 4 * DRAW_HELP, 9.3 * DRAW_HELP, 20, BLACK);
}

bool GUI::isMouseOnSolverButton()
{
    Vector2 mousePosition = GetMousePosition();
    int height_coord = mousePosition.y;
    int width_coord = mousePosition.x;

    if(((width_coord > (2.8 * DRAW_HELP))&& (width_coord < ((2.8 + 4) * DRAW_HELP)))
       && ((height_coord > (9.2 * DRAW_HELP)) && (height_coord < ((9.2 + 0.5) * DRAW_HELP))))
    {
        return true;
    }

    return false;
}


/*
int GUI::drawBoardSelection(std::vector<Board> boards)
{
    ///Test
    int board[3][8][8] = {0};

    board[0][2][3] = 1;
    board[0][2][4] = 1;
    board[0][2][5] = 1;

    board[1][3][1] = 1;
    board[1][4][1] = 1;
    board[1][5][1] = 1;

    board[2][0][3] = 1;
    board[2][1][4] = 1;
    board[2][2][5] = 1;
    ///
    //Boards
    for(int i = 0; i < 3; i++)
    {
        //vertical lines
        for(int column = 0; column < BOARD_WIDTH + 1; column++)
        {
            DrawLine((i * 600) + 3 * DRAW_HELP_BOARDSELECTION + column * DRAW_HELP_BOARDSELECTION, 10 * DRAW_HELP_BOARDSELECTION, (i * 600) + 3 * DRAW_HELP_BOARDSELECTION + column * DRAW_HELP_BOARDSELECTION, 18 * DRAW_HELP_BOARDSELECTION, BLACK);
        }
        // horizontal lines
        for(int row = 0; row < BOARD_HEIGHT + 1; row++)
        {
            DrawLine((i * 600) + 3 * DRAW_HELP_BOARDSELECTION ,  (10 + row) * DRAW_HELP_BOARDSELECTION, (i * 600) + 11 * DRAW_HELP_BOARDSELECTION, (10 + row) * DRAW_HELP_BOARDSELECTION, BLACK);
        }

        //int** board = Board::getBoard();





        for(int column = 0; column < BOARD_HEIGHT; column++)
        {
            for(int row = 0; row < BOARD_WIDTH; row++)
            {
                if(boards[i].getBoard()[row][column] != 0) //Switched row and column
                {
                    DrawRectangle((i * 600) + 3 * DRAW_HELP_BOARDSELECTION + column * DRAW_HELP_BOARDSELECTION, (10 + row) * DRAW_HELP_BOARDSELECTION, DRAW_HELP_BOARDSELECTION, DRAW_HELP_BOARDSELECTION, BLACK);
                }
            }
        }
    }
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
*/