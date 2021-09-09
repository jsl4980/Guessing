#include <gtest/gtest.h>
#include "../round.h"

using namespace testing;

TEST(RoundTests, Constructor)
{
    Round round;
    EXPECT_EQ(round.getClues(), 0);
    EXPECT_EQ(round.getQuestions(), 0);
}

TEST(RoundTests, GiveClues)
{
    Round round;
    EXPECT_EQ(round.giveClue(), 1);
    EXPECT_EQ(round.getClues(), 1);
    EXPECT_EQ(round.giveClue(), 2);
}
