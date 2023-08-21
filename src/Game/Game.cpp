#include "../Game/Game.hpp"


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

void Game::placeStartblocksGenerate(int difficulty) {
    std::vector<Block> startblocks = Board::getNotPlacedStartBlocks();
    int loopiterator = 0;
    int blockiterator = 0;

    int solverDifficulty;
    do
    {
        m_board.clearBoard();
        loopiterator = 0;
        blockiterator = 0;
        for (auto block : startblocks)
        {
            int placecheck = 1;

            //if(blockiterator < 2)
            //{
                // Rotation
                if(Board::generateRotation()) // if true rotate once, if false don't rotate
                {
                    Board::rotateBlockOnHand(block);
                }
                //place
                do
                {
                    placecheck = Board::placeBlock(block, Board::generateCoordinate(), Board::generateCoordinate());
                } while(!placecheck);
            //}
            /*
            else
            {
                do {
                    Board::removeBlock(block);
                    if(Board::generateRotation()) // if true rotate once, if false don't rotate
                    {
                        Board::rotateBlockOnHand(block);
                    }
                    //place
                    do
                    {
                        placecheck = Board::placeBlock(block, Board::generateCoordinate(), Board::generateCoordinate());
                        if(!placecheck)
                        {
                            Board::removeBlock(block);
                        }
                        loopiterator++;
                    } while(!placecheck);
                    auto solver = new Solver;
                    solverDifficulty = solver->solve(difficulty);
                    delete solver;
                }
                while(solverDifficulty != difficulty || loopiterator < 20);
            }
             */
            blockiterator++;

        }
        std::cout << "Durchlauch\n";
        auto solver = new Solver;
        solverDifficulty = solver->solve(difficulty);
        delete solver;
    }while(!solverDifficulty);

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
    //Initialisation of the Window
    initStartblocks();
    initPlayblocks();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    bool shouldSolve;

    std::cout << "GUITest" << std::endl;
    //Loop for Playing
    while(!WindowShouldClose())
    {
        //Drawing everything that needs to be drawn
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_gui.drawGameBackground();
        m_gui.drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());
        m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
        m_gui.drawSolverButton();
        Block block;

        EndDrawing();

        //Drag and Drop Logic
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            //Solver Button logic and Drawing
            shouldSolve = m_gui.isMouseOnSolverButton();
            if(shouldSolve)
            {
                std::cout << "Solve it\n";
                if(m_solver.solve(-1))
                {
                    Board::setBoard(m_solver.getWinningBoard());
                    Board::placeAllBlocks();

                }


            }
            //Drag and Drop finding the block to move
            BlockType blockType = m_gui.isMouseOnBlock();
            if(blockType == BlockType::ONEBYONE || blockType == BlockType::ONEBYTWO || blockType == BlockType::ONEBYTHREE)
            {
                continue;
            }
            block = m_gui.findBlockFromType(blockType);
            Board::removePlacedBlock(block);
            Board::removeNotPlacedBlock(block);
            Board::removeBlock(block);

            //Moving the Block
            while(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if(IsKeyPressed(KEY_R))
                {
                    m_board.rotateBlockOnHand(block);
                    std::cout << "Rotatet Block\n";
                }

                //Keep drawing everything
                BeginDrawing();
                ClearBackground(RAYWHITE);
                m_gui.drawGameBackground();
                m_gui.drawNotPlacedBlocks(Board::getNotPlacedPlayBlocks());
                m_gui.drawPlacedBlocks(Board::getPlacedBlocks());
                m_gui.drawBlockAtMouse(blockType);
                m_gui.drawSolverButton();
                EndDrawing();
            }
            //Logic to actual place a Block
            std::tuple<int, int> mouseCoordinates= m_gui.calculateMouseCoordinates();
            int height_coord = std::get<0>(mouseCoordinates);
            int width_coord = std::get<1>(mouseCoordinates);
            //if((0 <= width_coord < BOARD_WIDTH) && (0 <= height_coord < BOARD_HEIGHT))
            {
                if(m_board.placeBlock(block, height_coord, width_coord))
                {
                    //Board::setPlacedBlock(block);
                    std::cout << "Block Placed on " << height_coord << " * " << width_coord <<"\n";
                    Board::printBoard();
                }
                else
                {
                    //Board::setNotPlacedPlayBlock(block);
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
            difficultySelection();
        }
        if(debugo == 2)
        {
            CloseWindow();
            buildGame();
        }
        if(debugo == 3)
        {
            CloseWindow();
            showTips();
        }
        EndDrawing();
    }
}

void Game::difficultySelection()
{
    //m_board.initBoard();
    initStartblocks();
    initPlayblocks();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    std::cout << "difficultySelection" << std::endl;
    int selection;


    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        selection = m_gui.drawDifficultySelection();

        if(selection == 1){boardGeneration(1);
            GamePlay();}

        if(selection == 2){boardGeneration(2);
            GamePlay();}

        if(selection == 3){boardGeneration(3);
            GamePlay();}

        EndDrawing();
        //Board::printBoard();
    }
}

void Game::showTips()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GUI");
    SetTargetFPS(60);

    std::cout << "showTips" << std::endl;
    int selection;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        m_gui.drawShowTips();

        EndDrawing();
    }
}

void Game::boardGeneration(int difficulty)
{
    int randomboard;

    difficulty -= 1;

    int xCoordinatesBlocks[3][3][3] = {0};
    int yCoordinatesBlocks[3][3][3] = {0};

    //Hardcoded Boards are following

    //First Board easy
    xCoordinatesBlocks[0][0][0] = 7;
    yCoordinatesBlocks[0][0][0] = 6;

    xCoordinatesBlocks[0][1][0] = 2;
    yCoordinatesBlocks[0][1][0] = 6;

    xCoordinatesBlocks[0][2][0] = 5;
    yCoordinatesBlocks[0][2][0] = 7;

    //Second Board easy
    xCoordinatesBlocks[0][0][1] = 5;
    yCoordinatesBlocks[0][0][1] = 4;

    xCoordinatesBlocks[0][1][1] = 0;
    yCoordinatesBlocks[0][1][1] = 5;

    xCoordinatesBlocks[0][2][1] = 4;
    yCoordinatesBlocks[0][2][1] = 0;

    //Third Board easy
    xCoordinatesBlocks[0][0][2] = 7;
    yCoordinatesBlocks[0][0][2] = 4;

    xCoordinatesBlocks[0][1][2] = 4;
    yCoordinatesBlocks[0][1][2] = 4;

    xCoordinatesBlocks[0][2][2] = 5;
    yCoordinatesBlocks[0][2][2] = 7;

    //First Board medium
    xCoordinatesBlocks[1][0][0] = 4;
    yCoordinatesBlocks[1][0][0] = 6;

    xCoordinatesBlocks[1][1][0] = 4;
    yCoordinatesBlocks[1][1][0] = 1;

    xCoordinatesBlocks[1][2][0] = 5;
    yCoordinatesBlocks[1][2][0] = 0;

    //Second Board medium
    xCoordinatesBlocks[1][0][1] = 2;
    yCoordinatesBlocks[1][0][1] = 3;

    xCoordinatesBlocks[1][1][1] = 1;
    yCoordinatesBlocks[1][1][1] = 6;

    xCoordinatesBlocks[1][2][1] = 5;
    yCoordinatesBlocks[1][2][1] = 0;

    //Third Board medium
    xCoordinatesBlocks[1][0][1] = 7;
    yCoordinatesBlocks[1][0][1] = 1;

    xCoordinatesBlocks[1][1][1] = 0;
    yCoordinatesBlocks[1][1][1] = 7;

    xCoordinatesBlocks[1][2][1] = 2;
    yCoordinatesBlocks[1][2][1] = 3;

    //First Board hard
    xCoordinatesBlocks[2][0][0] = 6;
    yCoordinatesBlocks[2][0][0] = 7;

    xCoordinatesBlocks[2][1][0] = 0;
    yCoordinatesBlocks[2][1][0] = 2;

    xCoordinatesBlocks[2][2][0] = 2;
    yCoordinatesBlocks[2][2][0] = 4;

    //Second Board hard
    xCoordinatesBlocks[2][0][1] = 0;
    yCoordinatesBlocks[2][0][1] = 3;

    xCoordinatesBlocks[2][1][1] = 1;
    yCoordinatesBlocks[2][1][1] = 6;

    xCoordinatesBlocks[2][2][1] = 0;
    yCoordinatesBlocks[2][2][1] = 2;

    //Third Board hard
    xCoordinatesBlocks[2][0][1] = 7;
    yCoordinatesBlocks[2][0][1] = 6;

    xCoordinatesBlocks[2][1][1] = 3;
    yCoordinatesBlocks[2][1][1] = 4;

    xCoordinatesBlocks[2][2][1] = 2;
    yCoordinatesBlocks[2][2][1] = 3;



    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 2);
    randomboard = distribution(generator);


    std::vector<Block> startblocks = Board::getNotPlacedStartBlocks();

    for (auto block : startblocks)
    {
        //place
        int blocknumber = static_cast<int>(block.type);
        blocknumber -= 1;
        Board::placeBlock(block, yCoordinatesBlocks[difficulty][blocknumber][randomboard] , xCoordinatesBlocks[difficulty][blocknumber][randomboard] );
    }


}
