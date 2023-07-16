#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

int sum(int arr[]) // OR (int *arr)
{
    int total = 0;

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << "\n";

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
        total += arr[i];
    }

    return total;
}

int main()
{

    int arr[] = {10, 11, 12, 13};

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << "\n";

    cout << sum(arr);

    return 0;
}