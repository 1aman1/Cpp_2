#include <iostream>
#include <queue>

int main()
{
    std::queue<std::pair<int, int>> queue;

    queue.push({1, 1});

    const auto [i, j] = queue.front();

    std::cout << i << "\n";

    return 0;
}