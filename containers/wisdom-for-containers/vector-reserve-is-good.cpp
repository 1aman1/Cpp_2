#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> v;

    // this line causes whole difference where iterator gets invalidated if we dont reserve memory in advance
    v.reserve(10);

    v.push_back(100);
    v.push_back(50);

    auto itr = std::find(v.begin(), v.end(), 50);

    std::cout << std::distance(v.begin(), itr) << " dist\n";

    v.insert(v.begin() + 2, 5);
    v.insert(v.begin() + 2, 20);
    v.insert(v.begin() + 2, 120);

    std::cout << std::distance(v.begin(), itr) << " dist\n";

    return 0;
}
