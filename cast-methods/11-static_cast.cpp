#include <iostream>
using namespace std;

struct Int
{
    int data;

    Int(int data) : data(data) { cout << "conversion ctor\n"; };

    operator string()
    {
        cout << "conversion operator\n";
        return to_string(data);
    };
};

int main()
{
    Int obj(80);

    string S = obj;
    obj = 80;

    std::cout << S << "\n";
    std::cout << obj.data << "\n";

    string S2 = static_cast<string>(obj);
    obj = static_cast<Int>(900);

    return 0;
}