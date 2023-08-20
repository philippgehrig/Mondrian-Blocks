#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../Board/Board.hpp"
#include <vector>

class Solver
{
public:
    Solver()
    : m_wining_board{{0}}
    , m_is_impossible{false}
    , m_win{false}
    {};

    ~Solver()
    {};

    void solve(std::optional<int**> board);
    void setWinningBoard(int** board);
    void nextPiece(int** board);

    bool getWin();



private:
    int m_difficulty;
    bool m_win;
    bool m_is_impossible;
    int m_wining_board[BOARD_HEIGHT][BOARD_WIDTH];
    int m_board_state[BOARD_HEIGHT][BOARD_WIDTH];
    int m_open_spawns = 0;
    int m_place_try_counter = 0;

};


#endif