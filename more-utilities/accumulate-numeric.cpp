#include <iostream>
#include <vector>
#include <numeric>

int main()
{

    std::vector<int> v{1, 2, 3, 4, 5};

    std::cout << std::accumulate(v.begin(), v.begin() + 4, 0);

    return 0;
}