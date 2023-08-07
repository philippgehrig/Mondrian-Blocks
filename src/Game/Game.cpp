#include "../Game/Game.hpp"

void Game::start()
{
    // Creation of blocks and placing them in board or container
    initStartblocks();
    // placeStartblocks();
    initPlayblocks();

    // GUI
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mondrian Blocks");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        m_gui.drawBoard();
        EndDrawing();
    }

}

void Game::initStartblocks()
{
    Block startBlock1 = {BlockType::ONEBYONE, 1, 1};
    Block startBlock2 = {BlockType::ONEBYTWO, 1, 2};
    Block startBlock3 = {BlockType::ONEBYTHREE, 1, 3};
    std::vector <Block> startblocks {startBlock1, startBlock2, startBlock3};
    Board::setNotPlacedStartBlocks(startblocks);
}

std::vector<Board> Game::placeStartblocks()
{
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

void Game::initPlayblocks() {
    Block PBlock2x2 = {BlockType::TWOBYTWO, 2, 2};
    Block PBlock1x4 = {BlockType::ONEBYFOUR, 1, 4};
    Block PBlock2x5 = {BlockType::TWOBYFIVE, 2, 5};
    Block PBlock2x3 = {BlockType::TWOBYTHREE, 2, 3};
    Block PBlock1x5 = {BlockType::ONEBYFIVE, 1, 5};
    Block PBlock3x3 = {BlockType::THREEBYTHREE, 3, 3};
    Block PBlock2x4 = {BlockType::TWOBYFOUR, 2, 4};
    Block PBlock3x4 = {BlockType::THREEBYFOUR, 3, 4};

    std::vector<Block> playblocks {PBlock3x4, PBlock2x5, PBlock3x3, PBlock2x4, PBlock2x3, PBlock1x5, PBlock1x4, PBlock2x2};
    Board::setNotPlacedStartBlocks(playblocks);
}
