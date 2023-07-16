#include "core.hh"
#include "utility.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace CORE;

Board::Board(int row, int col) : _row(row), _col(col) {
    assert(row > 0 && col > 0);
    _slots.resize(row);
    for (int i = 0; i < row; i++) {
        _slots[i].resize(col);
    }
}

bool Board::gameOver() {
    std::vector<std::pair<int,int>> emptyPositions;
    getEmptySlots(emptyPositions);
    if (emptyPositions.empty()) {
        return true;
    }
    return false;
}

bool Board::generateRandomNumber(int &x, int &y, int &val) {
    std::vector<std::pair<int,int>> emptySlots;
    getEmptySlots(emptySlots);
    if (emptySlots.empty()) {
        return false;
    }

    int idx = Utility::getInstance().randomInRange(0, emptySlots.size());
    x = emptySlots[idx].first;
    y = emptySlots[idx].second;

    // random value is 2 or 4
    static const std::vector<int> randValues = {2, 4};
    int valIdx = Utility::getInstance().randomInRange(0, 2);
    assert(valIdx != 2);
    val = randValues[valIdx];
    return true;
}

bool Board::success() {
    std::vector<std::pair<int,int>> targetPoses;
    getValueSlots(2048, targetPoses);
    return !targetPoses.empty();
}

void Board::left() {
    // all numbers are moving to the left
    for (int row = 0; row < _row; row++) {
        int hasNumSlotCol = -1;
        for (int col = 0; col < _col; col++) {
            int& curVal = _slots[row][col];
            if (curVal == 0) {
                continue;
            }
            // first element in the row
            if (hasNumSlotCol == -1) {
                hasNumSlotCol = 0;
                if (col == 0) {
                    continue;
                }
                _slots[row][0] = curVal;
                curVal = 0;
                continue;
            }

            // check if can merge
            int& preVal = _slots[row][hasNumSlotCol];
            if (preVal == curVal) {
                // it can merge
                preVal += curVal;
                curVal = 0;
                continue;
            }

            // can't merge
            assert(hasNumSlotCol < col);
            if (col == hasNumSlotCol+1) {
                // adjacent, skip
                hasNumSlotCol += 1;
                continue;
            }
            assert(_slots[row][hasNumSlotCol+1] == 0);
            _slots[row][++hasNumSlotCol] = curVal;
            curVal = 0;
        }
    }
}

void Board::right() {
    // all numbers are moving to the right
    for (int row = 0; row < _row; row++) {
        int hasNumSlotCol = -1;
        for (int col = _col - 1; col >= 0; col--) {
            int& curVal = _slots[row][col];
            if (curVal == 0) {
                continue;
            }
            // first element in the row
            if (hasNumSlotCol == -1) {
                hasNumSlotCol = _col - 1;
                if (col == _col-1) {
                    continue;
                }
                _slots[row][_col-1] = curVal;
                curVal = 0;
                continue;
            }

            // check if it can merge
            int& preVal = _slots[row][hasNumSlotCol];
            if (preVal == curVal) {
                // it can merge
                preVal += curVal;
                curVal = 0;
                continue;
            }

            // can't merge
            assert(hasNumSlotCol < col);
            if (col == hasNumSlotCol-1) {
                // adjacent, skip
                hasNumSlotCol -= 1;
                continue;
            }
            assert(_slots[row][hasNumSlotCol-1] == 0);
            _slots[row][++hasNumSlotCol] = curVal;
            curVal = 0;
        }
    }
}

void Board::up() {
    // all numbers are moving to the top
    for (int col = 0; col < _col; col++) {
        int hasNumSlotRow = -1;
        for (int row = _row - 1; row >= 0; row--) {
            int& curVal = _slots[row][col];
            if (curVal == 0) {
                continue;
            }
            // first element in the column
            if (hasNumSlotRow == -1) {
                hasNumSlotRow = _row - 1;
                if (row == _row - 1) {
                    // the first row has element
                    continue;
                }
                _slots[_row - 1][col] = curVal;
                curVal = 0;
                continue;
            }

            int& preVal = _slots[hasNumSlotRow][col];
            if (preVal == curVal) {
                // merge
                preVal += curVal;
                curVal = 0;
                continue;
            }

            // can't merge
            assert(hasNumSlotRow >= 0);
            if (row == hasNumSlotRow - 1) {
                // adjacent, skip
                hasNumSlotRow -= 1;
                continue;
            }
            assert(_slots[row][hasNumSlotRow - 1] == 0);
            _slots[row][--hasNumSlotRow] = curVal;
            curVal = 0;
        }
    }
}

void Board::down() {
    // all numbers are moving to the bottom
    for (int col = 0; col < _col; col++) {
        int hasNumSlotRow = -1;
        for (int row = 0; row < _row; row++) {
            int& curVal = _slots[row][col];
            if (curVal == 0) {
                continue;
            }
            // first element in the column
            if (hasNumSlotRow == -1) {
                hasNumSlotRow = 0;
                if (row == 0) {
                    // the first row has element
                    continue;
                }
                _slots[0][col] = curVal;
                curVal = 0;
                continue;
            }

            // check if can merge
            int& preVal = _slots[hasNumSlotRow][col];
            if (preVal == curVal) {
                // it can merge
                preVal += curVal;
                curVal = 0;
                continue;
            }

            // can't merge
            assert(hasNumSlotRow < row);
            if (row == hasNumSlotRow + 1) {
                // adjacent, skip
                hasNumSlotRow += 1;
                continue;
            }
            assert(_slots[row][hasNumSlotRow+1] == 0);
            _slots[row][++hasNumSlotRow] = curVal;
            curVal = 0;
        }
    }
}

bool Board::setNumberAtPos(int row, int col, int val) {
    if (row < 0 || row > _row) {
        return false;
    }
    if (col < 0 || col > _col) {
        return false;
    }
    _slots[row][col] = val;
    return true;
}

void Board::print() {
    for (int row = 0; row < _row; row++) {
        for (int col = 0; col < _col; col++) {
            std::cout << _slots[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int Board::getNumberAtPos(int row, int col) {
    return 0;
}

void Board::getEmptySlots(std::vector<std::pair<int, int>> &poses) {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            if (_slots[i][j] == 0) {
                poses.push_back({i, j});
            }
        }
    }
}

void Board::getValueSlots(int value, std::vector<std::pair<int, int>> &valPoses) {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            if (_slots[i][j] == value) {
                valPoses.push_back({i,j});
            }
        }
    }
}