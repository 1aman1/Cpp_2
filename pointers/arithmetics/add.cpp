#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

int main()
{

    int x[4] = {10, 11, 12, 13};

    cout << &x << "\n";
    cout << *x << "\n";
    cout << *(x + 0) << "\n";
    cout << *(x + 1) << "\n";
    cout << *(x + 2) << "\n";

    return 0;
}