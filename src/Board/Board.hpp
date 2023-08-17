#ifndef BOARD_HPP
#define BOARD_HPP

#include "../Constants.hpp"
#include "../Block/Block.hpp"
#include <vector>
#include <optional>
#include <iostream>
#include <random>
#include <tuple>
#include <algorithm>

/**
 * @brief Board class. Implemented as static class -> only one instance of the board is possible
 * @usage_example Board::getBoard() to get the board
 */

class Board
{
public:
    Board() = default;
    ~Board()= default;

    /**
     * @brief getter for the board (2d array)
     * @return 2d array representing the board
     */
    static int** getBoard()
    {
        int** boardCopy = new int*[BOARD_HEIGHT];
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            boardCopy[i] = new int[BOARD_WIDTH];
            for (int j = 0; j < BOARD_WIDTH; j++) {
                boardCopy[i][j] = m_board[i][j];
            }
        }
        return boardCopy;
    }

    /**
     * @brief getter for the not placed play blocks
     * @return vector of blocks that are not placed on the board
     */
    static std::vector<Block> getNotPlacedPlayBlocks()
    {
        return m_notPlacedPlayBlocks;
    }

    /**
     * @brief setter for the not placed play blocks (multiple blocks)
     * @param blocks: vector of blocks that are not placed on the board
     */
    static void setNotPlacedPlayBlocks(std::vector<Block> blocks)
    {
        m_notPlacedPlayBlocks = std::move(blocks);
    }

    /**
     * @brief setter for the not placed play blocks (single block)
     * @param block: block that is not placed on the board
     */
    static void setNotPlacedPlayBlock(const Block& block)
    {
        m_notPlacedPlayBlocks.push_back(block);
    }

    /**
     * @brief getter for the not placed start blocks
     * @return vector of blocks that are not placed on the board
     */
    static std::vector<Block> getNotPlacedStartBlocks()
    {
        return m_notPlacedStartBlocks;
    }

    /**
     * @brief setter for the not placed start blocks (multiple blocks)
     * @param blocks: vector of blocks that are not placed on the board
     */
    static void setNotPlacedStartBlocks(std::vector<Block> blocks)
    {
        m_notPlacedStartBlocks = std::move(blocks);
    }

    /**
     * @brief setter for the not placed start blocks (single block)
     * @param block: block that is not placed on the board
     */
    static void setNotPlacedStartBlock(const Block& block)
    {
        m_notPlacedStartBlocks.push_back(block);
    }


    /**
 * @brief getter for the placed blocks
 * @return vector of blocks that are not placed on the board
 */
    static std::vector<Block> getPlacedBlocks()
    {
        return m_placedBlocks;
    }

    /**
     * @brief setter for the placed blocks (multiple blocks)
     * @param blocks: vector of blocks that are not placed on the board
     */
    static void setPlacedBlocks(std::vector<Block> blocks)
    {
        m_placedBlocks = std::move(blocks);
    }

    /**
     * @brief setter for the placed blocks (single block)
     * @param block: block that is not placed on the board
     */
    static void setPlacedBlock(const Block& block)
    {
        m_placedBlocks.push_back(block);
    }

    /**
     * @brief removes element from placed blocks vector
     * @param block: the block which will be removed
     */
     static void removePlacedBlock(Block& block)
     {
        for(auto it = m_placedBlocks.begin(); it != m_placedBlocks.end(); ++it)
        {
            if (*it == block.type) {
                m_placedBlocks.erase(it);
                break;
            }
        }
        std::cout << "Block ist nicht vorhanden\n";
     }

    /**
   * @brief removes element from not placed blocks vector
   * @param block: the block which will be removed
   */
    static void removeNotPlacedBlock(Block& block)
    {
        for(auto it = m_notPlacedPlayBlocks.begin(); it != m_notPlacedPlayBlocks.end(); ++it)
        {
            if (*it == block.type) {
                m_notPlacedPlayBlocks.erase(it);
                break;
            }
        }
        std::cout << "Block ist nicht vorhanden\n";
    }

    // ------------

    /**
* @brief getter for all Blocks
* @return vector of blocks that are not placed on the board
*/
    static std::vector<Block> getAllBlocks()
    {
        return m_allBlocks;
    }

    /**
     * @brief setter for all Blocks (multiple blocks)
     * @param blocks: vector of blocks that are not placed on the board
     */
    static void setAllBlocks(std::vector<Block> blocks)
    {
        m_allBlocks = std::move(blocks);
    }

    /**
     * @brief setter for all Blocks (single block)
     * @param block: block that is not placed on the board
     */
    static void setAllBlock(const Block& block)
    {
        m_allBlocks.push_back(block);
    }

    // ----------


    /**
     * @brief checks if block can be placed
     * @param block: block that is to be placed
     * @param height_coord y-coordinate of the block (column) (top left corner)
     * @param width_coord x-coordinate of the block (row) (top left corner)
     * @return true if the block can be placed, false otherwise
     **/
    static bool canPlaceBlock(const Block& block, int height_coord, int width_coord)
    {
        for(int column = height_coord; column < height_coord + block.height; column++){
            for(int row = width_coord; row < width_coord + block.width; row++)
            {
                if(column >= BOARD_HEIGHT || row >= BOARD_WIDTH)
                {
                    return false;
                }

                if(m_board[column][row] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * @brief place a block on the board
     * @param block: block to be placed
     * @param height_coord y-coordinate of the block (column) (top left corner)
     * @param width_coord x-coordinate of the block (row) (top left corner)
     * @return true if the block was placed successfully, false otherwise
     */
    static bool placeBlock(Block& block, const int height_coord, const int width_coord)
    {
        //if block can be placed
        if(canPlaceBlock(block, height_coord, width_coord))
        {
            for(int column = height_coord; column < height_coord + block.height; column++){
                for(int row = width_coord; row < width_coord + block.width; row++)
                {
                    m_board[column][row] = static_cast<int>(block.type);
                }
            }

            return true;
        }
        else return false;
    }

    /**
     * @brief place a block on the board (used by solver)
     * @param block: block to be placed
     * @param height_coord y-coordinate of the block (column) (top left corner)
     * @param width_coord x-coordinate of the block (row) (top left corner)
     * @return true if the block was placed successfully, false otherwise
     */
    static bool placeBlockSolver(Block& block, const int height_coord, const int width_coord, int** board, bool rotated = false)
    {
        //if block can be placed
        if(canPlaceBlock(block, height_coord, width_coord))
        {
            if(rotated)
            {
                int tmp = block.height;
                block.height = block.width;
                block.width = tmp;
            }
            for(int column = height_coord; column < height_coord + block.height; column++){
                for(int row = width_coord; row < width_coord + block.width; row++)
                {
                    board[column][row] = static_cast<int>(block.type);
                }
            }
            return true;
        }
        else return false;
    }

    /**
     * @brief finds the block in the board
     * @param block to be find in the board
     * @return coordinates of the block as a tuple (y, x)
     * or null opt if the block isn't in the board
     */
    static std::optional<std::tuple<int, int>> findBlock(Block& block){
        for(int column = 0; column < BOARD_HEIGHT; column++){
            for(int row = 0; row < BOARD_WIDTH; row++)
            {
                if(m_board[column][row] == static_cast<int>(block.type))
                {
                    return std::make_tuple(column, row);
                }
            }
        }
        //return null opt if block isn't in the board
        return std::nullopt;
    }

    /**
     * @brief remove block from the board
     * @param block to be removed from the board
     * @return true if successfully removed, otherwise false (probably block wasn't placed yet)
     */
    static bool removeBlock(Block& block)
    {
        auto coordinates = findBlock(block);
        //if block was found in the board -> delete
        if(coordinates.has_value())
        {
            int height_coord = std::get<0>(coordinates.value());
            int width_coord = std::get<1>(coordinates.value());
            for(int column = height_coord; column < height_coord + block.height; column++){
                for(int row = width_coord; row < width_coord + block.width; row++)
                {
                    m_board[column][row] = 0;
                }
            }
            return true;
        }
        //block wasn't found
        else{
            return false;
        }
    }

    /**
     * @brief rotate block if it's not in the board
     * @param block
     * @return true if block was successfully rotated,
     * otherwise false (the block is probably in the board -> not possible to rotate)
     */
    static bool rotateBlock(Block& block)
    {
        auto res = findBlock(block);
        //if res == null opt (if block is not in the board)
        if(!res.has_value())
        {
            int tmp = block.height;
            block.height = block.width;
            block.width = tmp;
            return true;
        }
        else return false;
    }

    /**
     * @brief clears the board
     */
    static void clearBoard()
    {
        for(int column = 0; column < BOARD_HEIGHT; column++)
        {
            for(int row = 0; row < BOARD_WIDTH; row++)
            {
                m_board[column][row] = 0;
            }
        }
    }

    /**
     * @brief prints the board
     */
    static void printBoard()
    {
        for(int column = 0; column < BOARD_HEIGHT; column++)
        {
            for(int row = 0; row < BOARD_WIDTH; row++)
            {
                std::cout << m_board[column][row] << " ";
            }
            std::cout << std::endl;
        }
    }

    /**
     * @return 0 or 1. 1 -> rotate, 0 -> do not rotate
     */
    static int generateRotation()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 1);
        return dis(gen);
    }

    /**
     * @return 0-7 coordinate for height or width (call twice for 2 coordinates)
     */
    static int generateCoordinate()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 7);
        return dis(gen);
    }

    /**
     * @return true if board full, otherwise false
     */
    static bool isFull()
    {
        for(int column = 0; column < BOARD_HEIGHT; column++)
        {
            for(int row = 0; row < BOARD_WIDTH; row++)
            {
                if(m_board[column][row] == 0) return false;
            }
        }
        return true;
    }

    /**
     * @brief init board with 0
     */
     static void initBoard()
    {
        for(int column = 0; column < BOARD_HEIGHT; column++)
        {
            for(int row = 0; row < BOARD_WIDTH; row++)
            {
                m_board[column][row] = 0;
            }
        }
    }

private:
    /**
     * @param m_board: 2D array representing the board
     * @used internal logic and GUI
     * @values:
     * 0: empty
     * Starting Blocks:
     * 1: 1x1
     * 2: 1x2
     * 3: 1x3
     * Playblocks:
     * 4: 2x2
     * 5: 1x4
     * 6: 2x5
     * 7: 2x3
     * 8: 1x5
     * 9: 3x3
     * 10: 2x4
     * 11: 3x4
     **/
    static int m_board[BOARD_HEIGHT][BOARD_WIDTH];

    // Container for all blocks that are not placed on the board (so-called aside)
    static std::vector<Block> m_notPlacedPlayBlocks;

    // Container for start blocks
    static std::vector<Block> m_notPlacedStartBlocks;

    // Container for all placed blocks
    static std::vector<Block> m_placedBlocks;

    // Container for all blocks
    static std::vector<Block> m_allBlocks;

};

#endif 