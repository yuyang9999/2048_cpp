#pragma once



namespace CORE {

class Board {
public:
    Board(int row, int col) : _row(row), _col(col) {}

    /// @brief check if game is over or not
    /// @return 
    bool gameOver();

    /// @brief at free space to generate a random number between (2, 4, 8)
    /// @param x the position of x
    /// @param y the position of y
    /// @param val 
    void generateRandomNumber(int& x, int& y, int& val);

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
    
private:
    int _freeSlotNum;

    int _row;
    int _col;
};

}