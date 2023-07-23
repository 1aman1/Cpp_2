#include <gtest/gtest.h>
#include <vector>

class Stack
{
    std::vector<int> container;

public:
    void push(int x) { container.push_back(x); }

    int pop()
    {
        if (container.size() > 0)
        {
            int stackTop = container.back();
            container.pop_back();
            return stackTop;
        }

        return -1;
    }

    int size() { return container.size(); }
};

class myClassTest : public testing::Test
{
public:
    Stack myStack;
    void SetUp()
    {
        for (int i = 1; i <= 10; ++i)
            myStack.push(i);
        std::cout << "stack loaded\n";
    }

    void TearDown()
    {
        std::cout << "stack emptied\n";
    }
};

TEST_F(myClassTest, popTest)
{
    // Act
    int stackTop = 10;

    // Assert/Expect
    while (stackTop != 1)
    {
        ASSERT_EQ(myStack.pop(), stackTop--);
    }
}

TEST_F(myClassTest, sizeTest)
{
    // act
    int lastSize = 10;

    // assert
    for (int i = 10; i >= 0; --i)
    {
        ASSERT_EQ(myStack.size(), i);
        myStack.pop();
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}