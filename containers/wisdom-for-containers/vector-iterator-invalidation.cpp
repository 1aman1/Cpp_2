#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> v;

    // this line causes whole difference where iterator gets invalidated if we dont reserve memory in advance
    v.reserve(10);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    auto itr = std::find(v.begin(), v.end(), 3);
    std::cout << "\ncurrent->" << *itr;

    std::cout << "\ndist " << std::distance(v.begin(), itr);

    v.insert(v.begin(), 0);
    v.insert(v.begin(), -1);
    v.insert(v.begin(), -2);

    std::cout << "\ndist " << std::distance(v.begin(), itr);
    
    std::cout << "\ncurrent->" << *itr;

    return 0;
}
