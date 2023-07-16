
#include "gtest/gtest.h"
#include "core.hh"

using namespace CORE;

class BoardTest : ::testing::Test
{
public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST(BoardTest, createBoard)
{
    Board b(3, 3);
    b.setNumberAtPos(0, 0, 4);
    b.setNumberAtPos(0, 1, 4);
    b.right();
    b.print();
}