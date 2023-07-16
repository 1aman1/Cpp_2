#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>
#include <sstream>

int stoi(std::string item)
{
    std::stringstream ss(item);
    int result;
    ss >> result;
    return result;
}

template <class T>
std::string atoi(T item)
{
    std::stringstream ss;
    std::string result;
    ss << item;
    ss >> result;
    return result;
}

int main()
{
    if (atoi(9) != "9")
        std::cout << "integer\n";
    else
        std::cout << "std::string\n";

    if (stoi("9") == 9)
        std::cout << "integer\n";
    else
        std::cout << "std::string\n";

    return 0;
}