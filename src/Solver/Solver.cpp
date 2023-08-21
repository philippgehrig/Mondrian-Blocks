#include "Solver.hpp"

/**
 * @brief sets the pieces to the array, needed for the solver
 */
void Solver::setPieces() {
    Block PBlock2x2 = {BlockType::TWOBYTWO, 2, 2, RED};
    Block PBlock1x4 = {BlockType::ONEBYFOUR, 1, 4, GREEN};
    Block PBlock2x5 = {BlockType::TWOBYFIVE, 2, 5, BLUE};
    Block PBlock2x3 = {BlockType::TWOBYTHREE, 2, 3, PINK};
    Block PBlock1x5 = {BlockType::ONEBYFIVE, 1, 5, LIME};
    Block PBlock3x3 = {BlockType::THREEBYTHREE, 3, 3, DARKBLUE};
    Block PBlock2x4 = {BlockType::TWOBYFOUR, 2, 4, BROWN};
    Block PBlock3x4 = {BlockType::THREEBYFOUR, 3, 4, ORANGE};

    m_play_blocks[0] = {PBlock3x4};
    m_play_blocks[1] = {PBlock3x3};
    m_play_blocks[2] = {PBlock2x5};
    m_play_blocks[3] = {PBlock2x4};
    m_play_blocks[4] = {PBlock2x3};
    m_play_blocks[5] = {PBlock2x2};
    m_play_blocks[6] = {PBlock1x5};
    m_play_blocks[7] = {PBlock1x4};

}

/**
 * @return difficulty level, 0 if impossible
 */
int Solver::getDifficulty() {
    if(!m_is_impossible)
        return 0;
    if(m_try_counter < 3000)
        return 1;
    else if(m_try_counter < 15000)
        return 2;
    else return 3;
}

/**
 * @param difficulty to generate board, -1 to solve the board
 * @return difficulty level, 0 if impossible
 */
int Solver::solve(int difficulty) {
    setPieces();
    Board::printBoard();
    solvePiece(Board::getBoard(), difficulty);
    return getDifficulty();
}

/**
 * @brief sets the m_winning_board to the winning board
 * @param board
 */
void Solver::setWinningBoard(int **board) {
    for (int col = 0; col < BOARD_HEIGHT; col++) {
        for (int row = 0; row < BOARD_WIDTH; row++) {
            m_winning_board[col][row] = board[col][row];
        }
    }
}

/**
 * @brief returns a copy of the winning board
 * @return int**
 */
int** Solver::getWinningBoard()
{
    int** boardCopy = new int*[BOARD_HEIGHT];
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        boardCopy[i] = new int[BOARD_WIDTH];
        for (int j = 0; j < BOARD_WIDTH; j++) {
            boardCopy[i][j] = m_winning_board[i][j];
        }
    }
    return boardCopy;
}


/**
 * @brief prints the status of the solver, helper function
 */
void Solver::printStatus()
{
    std::cout << "Try counter " << m_try_counter << std::endl;
    std::cout << "Difficulty " << getDifficulty() << std::endl;
    std::cout << "Is won " << m_is_won << std::endl;
    std::cout << "Is impossible " << m_is_impossible << std::endl;
}


/**
 * @brief checks if all pieces are placed
 * @return true if all pieces are placed
 * @return false if not all pieces are placed
 */

bool Solver::isPlaced(int index) {
    for(auto & m_placed_block : m_placed_blocks)
    {
        if(m_placed_block.type == m_play_blocks[index].type)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief main recursive function to solve the board
 * @param board
 * @param difficulty: -1 for solve
 */
void Solver::solvePiece(int **board, int difficulty) {
    if (m_is_won || m_is_impossible) {
        return;
    }

    if(difficulty == 1) {
        if (!(m_try_counter > 3000 && m_try_counter < 15000 && m_is_won == true)) {
            return;
        }
    }else if (difficulty == 2) {
        if (!(m_try_counter > 15000 && m_try_counter < 60000 && m_is_won == true)) {
            return;
        }
    }else if (difficulty == 3) {
                if (!(m_try_counter > 60000 && m_try_counter < 100000000 && m_is_won == true)) {
                    return;
                }
            }

    if(m_try_counter > 100000000)
    {
        m_is_impossible = true;
    }

    if (allPiecesPlaced()) {
        m_is_won = true;
        setWinningBoard(board);
        return;
    }

    for (int col = 0; col < BOARD_HEIGHT; col++) {
        for (int row = 0; row < BOARD_WIDTH; row++) {
            for (int rotate = 0; rotate < 2; rotate++) {
                for (int index = 0; index < PLAYBLOCK_AMOUNT; index++) {
                    if (!isPlaced(index)) {
                        m_try_counter++;

                        //std::cout << m_try_counter << "\n";

                        // Prune this branch if the block can't be placed here
                        if (!Board::canPlaceBlockSolver(m_play_blocks[index], col, row, board, rotate)) {
                            continue;
                        }

                        if (Board::placeBlockSolver(m_play_blocks[index], col, row, board, rotate)) {
                            m_placed_blocks.push_back(m_play_blocks[index]);
                            solvePiece(board, difficulty);

                            //backtrack
                            m_placed_blocks.pop_back();
                            Board::removeBlockSolver(m_play_blocks[index], board);

                            // If a solution is found in the recursive call, exit the loops
                            if (m_is_won || m_is_impossible) {
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}


/**
 * @brief checks if all pieces are placed
 * @return true if all pieces are placed
 * @return false if not all pieces are placed
 */
bool Solver::allPiecesPlaced() const {
    return m_placed_blocks.size() == PLAYBLOCK_AMOUNT;
}




