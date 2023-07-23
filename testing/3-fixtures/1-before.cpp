#include <gtest/gtest.h>

class Base
{
    int data;

public:
    Base(int data) : data(data) {}

    void increment(int byX) { data += byX; }

    int getData() { return data; }
};

TEST(ClassTest, inc_by_5)
{
    // Arrange
    Base obj(100);
    // Act
    obj.increment(5);
    // Assert/Expect
    EXPECT_EQ(obj.getData(), 105);

    std::cout << "test flag\n";
}
/*
..
.. N TESTs
..

 */
TEST(ClassTest, inc_by_50)
{
    // Arrange
    Base obj(100);
    // Act
    obj.increment(50);
    // Assert/Expect
    EXPECT_EQ(obj.getData(), 150);

    std::cout << "test flag\n";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}