#include <gtest/gtest.h>

TEST(TestOne, SubTest1)
{
    ASSERT_TRUE(1 == 1);
    // ASSERT_FALSE(2 == 1);
}

TEST(TestTwo, SubTest2)
{
    // ASSERT_TRUE(1 == 1);
    ASSERT_FALSE(2 == 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
