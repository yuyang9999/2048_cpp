#pragma once
#include <vector>


namespace CORE {

class Board {
public:
    Board(int row, int col);

    /// @brief check if game is over or not
    /// @return 
    bool gameOver();

    /// @brief at free space to generate a random number between (2, 4, 8)
    /// @param x the position of x
    /// @param y the position of y
    /// @param val 
    bool generateRandomNumber(int& x, int& y, int& val);

    /// @brief check if the game success (got 2048)
    /// @return true if success, false otherwise
    bool success();

    // left swipe operation
    void left();

    // right swipe operation
    void right();

    // up swipe operation
    void up();

    // down swipe operation
    void down();

    bool setNumberAtPos(int row, int col, int val);

    int getNumberAtPos(int row, int col);

    void clear();

    void print();
    
private:
    void getEmptySlots(std::vector<std::pair<int, int>>& poses);

    void getValueSlots(int value, std::vector<std::pair<int,int>>& valPoses);

    std::vector<std::vector<int>> _slots;
    int _freeSlotNum;

    int _row;
    int _col;
};

}