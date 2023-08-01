#include <iostream>

class MyClass; // Forward declaration

class FriendClass
{
public:
    void showPrivateData(MyClass &obj);
};

class MyClass
{
private:
    int privateData;

public:
    MyClass(int data) : privateData(data) {}

    // Declare FriendClass as a friend
    friend class FriendClass;
};

void FriendClass::showPrivateData(MyClass &obj)
{
    std::cout << "Accessing privateData from FriendClass: " << obj.privateData << std::endl;
}

int main()
{
    MyClass obj(99);
    FriendClass fc;
    fc.showPrivateData(obj);
    return 0;
}
