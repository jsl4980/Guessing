#include <gtest/gtest.h>
#include "../animalgenerator.h"

TEST(AnimalGeneratorTests, Constructor) {
    AnimalGenerator ag;
    EXPECT_NE (nullptr, &ag);
}


