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
    m_play_blocks[6] = {PBlock2x2};
    m_play_blocks[6] = {PBlock1x5};
    m_play_blocks[7] = {PBlock1x4};

}

int Solver::solve() {
    setPieces();
    solvePiece(0, Board::getBoard());

    return 1;
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


void Solver::solvePiece(int index, int** board) {
    int** snapshot = board;

    //print snapshot
    for(int column = 0; column < BOARD_HEIGHT; column++)
    {
        for(int row = 0; row < BOARD_WIDTH; row++)
        {
            std::cout << snapshot[column][row] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    //

    for(int rotated = 0; rotated < 2; rotated++)
    {
        for(int y = 0; y < BOARD_HEIGHT; y++)
        {
            for(int x = 0; x < BOARD_WIDTH; x++)
            {
                m_try_counter++;
                if(Board::placeBlockSolver(m_play_blocks[index], y, x, snapshot,!!rotated))
                {
                    if(index == PLAYBLOCK_AMOUNT-1)
                    {
                        m_is_won = true;
                        setWinningBoard(snapshot);
                    }
                    else
                    {
                        std::cout << m_try_counter << std::endl;
                        solveNextPiece(index+1, snapshot);
                        snapshot = board;
                    }
                }
            }
        }
    }
}

void Solver::solveNextPiece(int new_index, int**newboard)
{
    m_open++;
    solvePiece(new_index, newboard);
    m_open--;
    if(m_open<1 && !m_is_won)
    {
        m_is_impossible = true;
    }
}

bool Solver::getWin()
{
    return m_is_won;
}



