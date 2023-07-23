#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect
{
public:
    virtual bool login(string username, string pwd) { return true; }
    virtual bool logout(string username) { return true; }
    virtual int fetchRecord() { return -1; }
};

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}