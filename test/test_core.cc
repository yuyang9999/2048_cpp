
#include "gtest/gtest.h"
#include "core.hh"
#include "utility.h"
#include <set>

using namespace CORE;

class BoardTest : public ::testing::Test
{
public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(BoardTest, testMoveDirection)
{
    // test right operation
    Board b(3, 3);
    b.setNumberAtPos(0, 0, 4);
    b.setNumberAtPos(0, 1, 4);
    b.print();
    b.right();
    b.print();
    ASSERT_TRUE(b.getNumberAtPos(0, 2) == 8);
    ASSERT_TRUE(b.getNumberAtPos(0, 1) == 0);
    ASSERT_TRUE(b.getNumberAtPos(0, 0) == 0);

    // test down operation
    b.clear();
    b.setNumberAtPos(0, 0, 2);
    b.setNumberAtPos(1, 0, 2);
    b.setNumberAtPos(2, 0, 2);
    b.print();
    b.down();
    b.print();
    ASSERT_TRUE(b.getNumberAtPos(1, 0) == 2);
    ASSERT_TRUE(b.getNumberAtPos(2, 0) == 4);

    // test left operation
    b.clear();
    b.setNumberAtPos(0, 0, 2);
    b.setNumberAtPos(0, 1, 2);
    b.setNumberAtPos(0, 2, 0);
    b.print();
    b.left();
    b.print();
    ASSERT_TRUE(b.getNumberAtPos(0, 0) == 4);
    ASSERT_TRUE(b.getNumberAtPos(0, 1) == 0);

    // test the up operation
    b.clear();
    b.setNumberAtPos(0, 0, 2);
    b.setNumberAtPos(2, 0, 2);
    b.print();
    b.up();
    b.print();
    ASSERT_TRUE(b.getNumberAtPos(0, 0) == 4);
}

TEST_F(BoardTest, testGenerateNumber)
{
    Board b(2,2);
    int row = 0, col = 0, val = 0;
    b.generateRandomNumber(row, col, val);
    ASSERT_TRUE(b.getNumberAtPos(row, col) == val);
    b.generateRandomNumber(row, col, val);
    b.generateRandomNumber(row, col, val);
    b.generateRandomNumber(row, col, val);
    b.print();
    ASSERT_TRUE(b.gameOver());

    b.setNumberAtPos(0, 0, 2048);
    ASSERT_TRUE(!b.gameOver());
    ASSERT_TRUE(b.success());
}

TEST_F(BoardTest, testRandomGenerator)
{
    std::set<int> ss;
    for (size_t i = 0; i < 50; i++) {
        int val = Utility::getInstance().randomInRange(0, 2);
        ss.insert(val);
    }
    for (auto& n : ss) {
        std::cout << n << std::endl;
    }
    ASSERT_TRUE(ss.size() == 2);
}
