#include "Solver.hpp"


void Solver::setWinningBoard(int **board) {
    for (int col = 0; col < BOARD_HEIGHT; col++) {
        for (int row = 0; row < 8; row++) {
            m_wining_board[col][row] = board[col][row];
        }
    }
}

void Solver::solve(std::optional<int**> board) {
    int** snapshot;
    if(!board.has_value()) snapshot = Board::getBoard();
    else snapshot = board.value();
    for(int rotated = 0; rotated < 2; rotated++)
    {
        for(int y = 0; y < BOARD_HEIGHT; y++)
        {
            for(int x = 0; x < BOARD_WIDTH; x++)
            {
                m_place_try_counter++;

                if(Board::placeBlockSolver(Board::getNotPlacedPlayBlocks()[0], y, x, snapshot,!!rotated))
                {
                    if(Board::getNotPlacedPlayBlocks().empty())
                    {
                        m_win = true;
                        setWinningBoard(snapshot);
                    }
                    else
                    {
                        Board::getNotPlacedPlayBlocks().erase(Board::getNotPlacedPlayBlocks().begin());
                        nextPiece(snapshot);
                        snapshot = board.value();
                    }
                }
            }
        }
    }
}

void Solver::nextPiece(int** board)
{
    m_open_spawns++;
    solve(board);
    m_open_spawns--;
    if(m_open_spawns<1 && !m_win)
    {
        m_is_impossible = true;
    }
}



