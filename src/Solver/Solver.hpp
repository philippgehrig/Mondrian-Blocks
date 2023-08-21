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
    {};

    ~Solver() = default;

    int solve(int difficulty);
    void setPieces();
    void solvePiece(int** board, int difficulty);
    void setWinningBoard(int** board);
    int** getWinningBoard();
    void printStatus();
    bool isPlaced(int index);
    int getDifficulty();


    bool allPiecesPlaced() const;

private:
    bool m_is_won;
    bool m_is_impossible;
    int m_winning_board[BOARD_HEIGHT][BOARD_WIDTH];
    int m_try_counter = 0;
    Block m_play_blocks[PLAYBLOCK_AMOUNT];
    std::vector<Block> m_placed_blocks = {};

};


#endif