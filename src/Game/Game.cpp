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

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // int game_mode = m_gui.drawStartScreen();
        EndDrawing();
        int game_mode = 1;
        switch(game_mode)
        {
            case 1:
                // placeStartblocksGenerate();
                buildGame();
                break;
            case 2:
                // placeOwnStartblocks();
                buildGame();
                break;
            default:
                DrawText("Error, please restart the Game", 10, 10, 20, RED);
                break;
        }
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

    auto blocks = Board::getAllBlocks();

}

std::vector<Board> Game::placeStartblocksGenerate() {
    std::vector<Block> startblocks = Board::getNotPlacedStartBlocks();
    std::vector<Board> Boards;
    for(int i = 0; i< 3; i++)
    {
        do
        {
            m_board.clearBoard();
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
            m_solver.solve(m_board.getBoard());
        }while(m_solver.getWin());
        Boards.push_back(m_board);
    }
    return Boards;
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

    std::vector<Block> playblocks
    {PBlock2x2, PBlock1x4, PBlock2x5, PBlock2x3, PBlock1x5, PBlock3x3, PBlock2x4, PBlock3x4};

    Board::setNotPlacedPlayBlocks(playblocks);
    Board::setAllBlocks(playblocks);

    auto blocks = Board::getAllBlocks();
}

void Game::buildGame()
{
    m_board.initBoard();
    initStartblocks();
    initPlayblocks();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    std::cout << "buildGame" << std::endl;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_gui.drawGameBackground();
        m_gui.drawNotPlacedStartBlocks(Board::getNotPlacedStartBlocks());
        m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
        Block block;

        if(IsKeyPressed(KEY_S))
        {
            CloseWindow();
            GamePlay();
            std::cout << "Starte Spiel\n";
        }

        EndDrawing();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            BlockType blockType = m_gui.isMouseOnStartBlock();
            block = m_gui.findBlockFromType(blockType);
            Board::removePlacedBlock(block);
            Board::removeNotPlacedStartBlock(block);
            Board::removeBlock(block);
            while(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                std::cout << (int)blockType << std::endl;
                if(IsKeyPressed(KEY_R))
                {
                    m_board.rotateBlockOnHand(block);
                    std::cout << "Rotatet Block\n";
                }

                BeginDrawing();
                ClearBackground(RAYWHITE);

                m_gui.drawGameBackground();
                m_gui.drawNotPlacedStartBlocks(Board::getNotPlacedStartBlocks());
                m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
                m_gui.drawBlockAtMouse(blockType);

                EndDrawing();
            }
            std::tuple<int, int> mouseCoordinates= m_gui.calculateMouseCoordinates();
            int height_coord = std::get<0>(mouseCoordinates);
            int width_coord = std::get<1>(mouseCoordinates);
            //if((0 <= width_coord < BOARD_WIDTH) && (0 <= height_coord < BOARD_HEIGHT))
            {
                if(m_board.placeBlock(block, height_coord, width_coord))
                {
                    Board::setPlacedBlock(block);
                    std::cout << "Block Placed on " << height_coord << " * " << width_coord <<"\n";
                    Board::printBoard();
                }
                else
                {
                    Board::setNotPlacedStartBlock(block);
                    std::cout << "Block not Placed\n";
                }

            }
        }
    }
}

void Game::GamePlay()
{
    //m_board.initBoard();
    initStartblocks();
    initPlayblocks();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    std::cout << "GUITest" << std::endl;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_gui.drawGameBackground();
        m_gui.drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());
        m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
        Block block;

        EndDrawing();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            BlockType blockType = m_gui.isMouseOnBlock();
            if(blockType == BlockType::ONEBYONE || blockType == BlockType::ONEBYTWO || blockType == BlockType::ONEBYTHREE)
            {
                continue;
            }
            block = m_gui.findBlockFromType(blockType);

            Board::removePlacedBlock(block);
            Board::removeNotPlacedBlock(block);
            Board::removeBlock(block);
            while(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if(IsKeyPressed(KEY_R))
                {
                    m_board.rotateBlockOnHand(block);
                    std::cout << "Rotatet Block\n";
                }

                BeginDrawing();
                ClearBackground(RAYWHITE);

                m_gui.drawGameBackground();
                m_gui.drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());
                m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
                m_gui.drawBlockAtMouse(blockType);

                /*
                std::tuple<int, int> mouseCoordinates= m_gui.calculateMouseCoordinates();
                int height_coord = std::get<0>(mouseCoordinates);
                int width_coord = std::get<1>(mouseCoordinates);
                */



                EndDrawing();
            }
            std::tuple<int, int> mouseCoordinates= m_gui.calculateMouseCoordinates();
            int height_coord = std::get<0>(mouseCoordinates);
            int width_coord = std::get<1>(mouseCoordinates);
            //if((0 <= width_coord < BOARD_WIDTH) && (0 <= height_coord < BOARD_HEIGHT))
            {
                if(m_board.placeBlock(block, height_coord, width_coord))
                {
                    Board::setPlacedBlock(block);
                    std::cout << "Block Placed on " << height_coord << " * " << width_coord <<"\n";
                    Board::printBoard();
                }
                else
                {
                    Board::setNotPlacedPlayBlock(block);
                    std::cout << "Block not Placed\n";
                }

            }
            if(Board::isFull())
            {
                // draw win screen
                CloseWindow();
                m_gui.drawWinScreen();
            }
        }
    }
}

void Game::play()
{
    m_board.initBoard();
    initStartblocks();
    initPlayblocks();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    std::cout << "debug" << std::endl;
    int debugo = 0;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        debugo = m_gui.drawStartScreen();
        if(debugo == 1)
        {
            CloseWindow();
            boardSelection();
        }
        if(debugo == 2)
        {
            CloseWindow();
            buildGame();
        }
        EndDrawing();
    }
}

void Game::boardSelection()
{
    //m_board.initBoard();
    initStartblocks();
    initPlayblocks();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    std::cout << "boardSelection" << std::endl;
    int selection;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        selection = m_gui.drawBoardSelection(m_board);

        if(selection == 1){GamePlay();}

        if(selection == 2){GamePlay();}

        if(selection == 3){GamePlay();}

        EndDrawing();
    }
}



