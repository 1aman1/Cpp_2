#include <iostream>
using namespace std;

struct IntToString
{
    int data;

    IntToString(int data) : data(data) { cout << "conversion ctor\n"; };

    operator string()
    {
        cout << "conversion operator\n";
        return to_string(data);
    };
};

int main()
{
    IntToString obj(80);

    string S = obj;
    obj = 160;

    std::cout << S << "\n";
    std::cout << obj.data << "\n";

    string S2 = static_cast<string>(obj);
    std::cout << S2 << "\n";

    obj = static_cast<IntToString>(240);
    std::cout << obj.data << "\n";

    return 0;
}