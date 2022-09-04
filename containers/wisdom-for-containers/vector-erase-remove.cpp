#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6};

    for (auto &e : vec)
        std::cout << e << " ";

    std::cout << "\nsize:" << vec.size();

    std::remove(vec.begin(), vec.end(), 3);

    std::cout << "\nsize:" << vec.size();

    for (auto itr = vec.begin(); itr != vec.end();)
    {
        if (*itr == 4)
            itr = vec.erase(itr);
        else
            ++itr;
    }

    std::for_each(vec.begin(), vec.end(),
                  [](int curr_val)
                  { std::cout << " : " << curr_val; });

    return 0;
}