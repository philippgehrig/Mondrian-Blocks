#include "Board.hpp"

int Board::m_board[BOARD_HEIGHT][BOARD_WIDTH] = {{0}}; // Initialize the 2D array to 0

std::vector<Block> Board::m_notPlacedPlayBlocks;
std::vector<Block> Board::m_notPlacedStartBlocks;
std::vector<Block> Board::m_placedBlocks;