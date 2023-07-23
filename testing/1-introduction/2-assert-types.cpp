#include <gtest/gtest.h>
#include <iostream>

TEST(TestOne, SubTest1)
{
    // ASSERT_EQ(1, 1); // SUCCESS
    ASSERT_NE(1, 2); // fatal failure - skips execution
    // EXPECT_EQ(1, 2); // non fatal failure - no skip

    // expect_eq: Checks if two values are equal.
    // expect_ne: Checks if two values are not equal.
    // expect_gt: Checks if the first value is greater than the second value.
    // expect_lt: Checks if the first value is less than the second value.
    // expect_ge: Checks if the first value is greater than or equal to the second value.
    // expect_le: Checks if the first value is less than or equal to the second value.

    std::cout << "test flag\n";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
