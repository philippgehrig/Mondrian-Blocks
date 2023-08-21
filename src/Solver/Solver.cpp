#include "Solver.hpp"

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

void Solver::solve() {
    setPieces();
    solvePiece(Board::getBoard());
}


void Solver::setWinningBoard(int **board) {
    for (int col = 0; col < BOARD_HEIGHT; col++) {
        for (int row = 0; row < BOARD_WIDTH; row++) {
            m_winning_board[col][row] = board[col][row];
        }
    }
}

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

void Solver::printStatus()
{
    std::cout << "Try counter " << m_try_counter << std::endl;
    std::cout << "Is won " << m_is_won << std::endl;
    std::cout << "Is impossible " << m_is_impossible << std::endl;
}


void Solver::solvePiece(int **board)
{
    auto localstate = board;

    for(int column = 0; column < BOARD_HEIGHT; column++)
    {
        for(int row = 0; row < BOARD_WIDTH; row++)
        {
            if(localstate[column][row] < 10) std::cout << " ";
            std::cout << localstate[column][row] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int rotate = 0; rotate < 2; rotate++) {
        for (int col = 0; col < BOARD_HEIGHT; col++) {
            for (int row = 0; row < BOARD_WIDTH; row++) {
                for (int index = 0; index < PLAYBLOCK_AMOUNT; index++) {
                    m_try_counter++;
                    if(col == 7 && row == 7 && rotate == 1 && index== 7)
                    {
                        std::cout << "impossible" << std::endl;
                        setWinningBoard(localstate);
                    }
                    if (isPlaced(index)) continue;
                    if (Board::placeBlockSolver(m_play_blocks[index], col, row, localstate, rotate)) {
                        m_placed_blocks.push_back(m_play_blocks[index]);
                        if (index == PLAYBLOCK_AMOUNT - 1 && m_placed_blocks.size() == PLAYBLOCK_AMOUNT){
                            m_is_won = true;
                            setWinningBoard(localstate);
                        } else {
                            localstate = board;
                            solvePiece(localstate);
                        }
                    }
                }
            }
        }
    }
}

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