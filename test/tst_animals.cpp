#include <gtest/gtest.h>
#include "../animal.h"

using namespace testing;

TEST(AnimalTest, Constructor) {
    Animal a;
    EXPECT_EQ(a.getName(), "");
}

TEST(AnimalTest, OtherConstructor) {
    Animal a("cat");
    EXPECT_EQ(a.getName(), std::string("cat"));
}
