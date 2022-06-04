#include <iostream>
using namespace std;

int main()
{
    int number, Kth;

    cin >> number >> Kth;
    if ((number >> Kth) & 1)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";

    // code
    return 0;
}
