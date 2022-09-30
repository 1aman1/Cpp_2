#include <iostream>
#include <unordered_map>

int main()
{
    std::string str = "racecar";
    int len_str = str.length();

    std::unordered_map<char, int> lookup_str;

    for (int i = 0; i < len_str; ++i)
    {
        ++lookup_str[str[i]];
    }

    for (auto itr = lookup_str.begin(); itr != lookup_str.end(); ++itr)
    {
        std::cout << itr->second << "\n";
    }

    return 0;
}
