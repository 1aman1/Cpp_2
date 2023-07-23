#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

class DataBaseConnect
{
public:
    virtual bool login(string username, string pwd) { return true; }
    virtual bool logout(string username) { return true; }
    virtual int fetchRecord() { return -1; }
};

class MockDB : public DataBaseConnect
{
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool(string username));
    MOCK_METHOD2(login, bool(string username, string password));
};

class MyDatabase
{
    DataBaseConnect &dbc;

public:
    MyDatabase(DataBaseConnect &dbc_) : dbc(dbc_) {}

    int Init(string username, string password)
    {
        if (dbc.login(username, password) != true)
        {
            cout << "db failure\n";
            return -1;
        }
        else
        {
            cout << "db success\n";
            return 1;
        }
    }
};

TEST(MyDBTest, LoginTest)
{
    // arrange
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, login("Terminator", "I'll be back"))
        .Times(1)
        .WillOnce(Return(true));

    // act
    int status = db.Init("Terminator", "I'll be back");

    // assert
    EXPECT_EQ(status, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}