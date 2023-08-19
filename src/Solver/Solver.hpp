#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../Board/Board.hpp"
#include <vector>

class Solver
{
public:
    Solver()
    : m_winning_board{{0}}
    , m_is_impossible{false}
    , m_is_won{false}
    , m_try_counter{0}
    , m_open{0}
    {};

    ~Solver() = default;

    void solve();
    void setPieces();
    void solvePiece(int index, int** board);
    void setWinningBoard(int** board);
    void solveNextPiece(int new_index, int** newboard);
    int** getWinningBoard();



private:
    int m_difficulty;
    bool m_is_won;
    bool m_is_impossible;
    int m_winning_board[BOARD_HEIGHT][BOARD_WIDTH];
    int m_open = 0;
    int m_try_counter = 0;
    Block m_play_blocks[PLAYBLOCK_AMOUNT];

};


#endif