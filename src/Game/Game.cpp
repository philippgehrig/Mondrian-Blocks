#include "../Game/Game.hpp"

void Game::start()
{
    // Creating of blocks
    m_board.initBoard();
    initStartblocks();
    initPlayblocks();

    // GUI
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mondrian Blocks");
    SetTargetFPS(60);

    int game_mode = 0;
    while(!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // game_mode = m_gui.drawStartScreen(); // return value 1 = play; 2 = play + set own start blocks; 3 = solve; 0 = nothing
        m_gui.drawGameBackground();
        m_gui.drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());


        switch(game_mode)
        {
            case 1:
                placeStartblocksGenerate();
                // draw boards to choose
                playGame();
                break;
            case 2:
                // placeOwnStartblocks();
                playGame();
                break;
            case 3:
                // placeOwnStartblocks();
                // solveGame();
                break;
            default:
                break;

        }
        EndDrawing();
    }

}

void Game::initStartblocks()
{
    Block startBlock1 = {BlockType::ONEBYONE, 1, 1, BLACK};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2, BLACK};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3, BLACK};
    std::vector <Block> startblocks {startBlock1, startBlock2, startBlock3};
    Board::setNotPlacedStartBlocks(startblocks);
    Board::setAllBlocks(startblocks);
}

std::vector<Board> Game::placeStartblocksGenerate() {
    std::vector<Block> startblocks = Board::getNotPlacedStartBlocks();
    for (auto block : startblocks)
    {
        int placecheck = 1;
        // Rotation
        if(Board::generateRotation()) // if true rotate once, if false don't rotate
        {
            Board::rotateBlock(block);
        }

        //place
        do
        {
            placecheck = Board::placeBlock(block, Board::generateCoordinate(), Board::generateCoordinate());
        } while(!placecheck);
    }

//    auto solutions = m_solver.solve(m_board);
//
//    int number_of_solutions = solutions.size();
//    if(!number_of_solutions) // if there is no solutions go in this if
//    {
//        Board::clearBoard();
//        placeStartblocks(startblocks);
//    }
//    else
//    {
//        return solutions;
//    }
}

void Game::initPlayblocks()
{
    Block PBlock2x2 = {BlockType::TWOBYTWO, 2, 2, RED};
    Block PBlock1x4 = {BlockType::ONEBYFOUR, 1, 4, GREEN};
    Block PBlock2x5 = {BlockType::TWOBYFIVE, 2, 5, BLUE};
    Block PBlock2x3 = {BlockType::TWOBYTHREE, 2, 3, PINK};
    Block PBlock1x5 = {BlockType::ONEBYFIVE, 1, 5, LIME};
    Block PBlock3x3 = {BlockType::THREEBYTHREE, 3, 3, DARKBLUE};
    Block PBlock2x4 = {BlockType::TWOBYFOUR, 2, 4, BROWN};
    Block PBlock3x4 = {BlockType::THREEBYFOUR, 3, 4, ORANGE};

    std::vector<Block> playblocks {PBlock2x2, PBlock1x4, PBlock2x5, PBlock2x3, PBlock1x5, PBlock3x3, PBlock2x4, PBlock3x4};

    Board::setNotPlacedPlayBlocks(playblocks);
    Board::setAllBlocks(playblocks);
}

void Game::playGame()
{
    BeginDrawing();
    m_gui.drawGameBackground();
    m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
    m_gui.drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());

    // Drag and Drop
    if(IsMouseButtonPressed(MouseButton ::MOUSE_LEFT_BUTTON))
    {
        BlockType type = m_gui.isMouseOnBlock();
        if(type > BlockType::ONEBYTHREE)
        {
            while (IsMouseButtonDown(MouseButton ::MOUSE_LEFT_BUTTON))
            {
                // m_gui.drawBlockAtMouse(type);
            }

        }

        // check if Board is full
        if(Board::isFull())
        {
            // draw win screen
            // m_gui.drawWinScreen();
        }
    }
    EndDrawing();
}

void Game::debug() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Debug");
    SetTargetFPS(60);

    std::cout << "debug" << std::endl;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_gui.drawStartScreen();
        EndDrawing();
    }
}


