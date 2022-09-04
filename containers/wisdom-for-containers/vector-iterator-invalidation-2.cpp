#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> v;

    v.reserve(10);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    auto itr = std::find(v.begin(), v.end(), 1);
    std::cout << "\ncurrent->" << *itr;

    std::cout << "\ndist " << std::distance(v.begin(), itr);

    v.insert(v.begin() + 2, 0);
    v.insert(v.begin() + 2, -1);
    v.insert(v.begin() + 2, -2);

    std::cout << "\ndist " << std::distance(v.begin(), itr);

    std::cout << "\ncurrent->" << *itr;

    return 0;
}
