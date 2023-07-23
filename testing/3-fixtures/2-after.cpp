#include <gtest/gtest.h>

class Base
{
    int data;

public:
    Base(int data) : data(data) {}

    void increment(int byX) { data += byX; }

    int getData() { return data; }
};

class myClassTest : public testing::Test
{
public:
    Base *ptrBase;
    void SetUp() { ptrBase = new Base(100); }

    void TearDown()
    {
        if (ptrBase != nullptr)
            delete ptrBase;
    }
};

TEST_F(myClassTest, inc_by_5)
{
    // Act
    ptrBase->increment(5);

    // Assert/Expect
    EXPECT_EQ(ptrBase->getData(), 105);

    std::cout << "test flag\n";
}

TEST_F(myClassTest, inc_by_50)
{
    // Act
    ptrBase->increment(50);

    // Assert/Expect
    EXPECT_EQ(ptrBase->getData(), 150);

    std::cout << "test flag\n";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}