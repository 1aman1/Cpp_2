#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);

    // traditional
    for (int itr = 0; itr < vec.size(); ++itr)
        std::cout << vec[itr] << " ";

    std::cout << std::endl;
    for (int itr = 0; itr < vec.size(); ++itr)
        std::cout << vec.at(itr) << " ";

    // Range based
    std::cout << std::endl;
    for (const auto &itr : vec)
        std::cout << itr << " ";

    std::cout << std::endl;
    for (const auto &itr : vec)
        std::cout << itr << " ";

    std::cout << std::endl;
    for (auto itr = vec.begin(); itr != vec.end(); ++itr)
        std::cout << *itr << " ";

    // c++20
    // std::cout << std::endl;
    // for (auto n = vec.size(); auto i : v)
    //     std::cout << --n << i << ' ';

    return 0;
}