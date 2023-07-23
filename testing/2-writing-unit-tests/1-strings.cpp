#include <gtest/gtest.h>
#include <iostream>

class myString
{
    std::string str;

public:
    myString(std::string s) : str(s) {}
    std::string GetString() { return str; }
};

TEST(TestOne, SubTest1)
{
    // Arrange
    myString obj("tree");

    // act
    std::string value = "Tree";

    // assert
    EXPECT_STRCASEEQ(obj.GetString().c_str(), value.c_str());

    // EXPECT_STREQ
    // EXPECT_STRNE
    // EXPECT_STRCASEEQ
    // EXPECT_STRCASENE

    std::cout << "test flag\n";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
