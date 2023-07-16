#include <iostream>
#include <list>
#include <algorithm>

typedef std::list<int> container_t;

static void print(const container_t &list)
{
    std::cout << std::endl;
    std::for_each(list.cbegin(),
                  list.cend(),
                  [](const int &i)
                  { std::cout << i << " : "; });
}

int main()
{
    // implemented as DLL
    container_t list = {100, 200, 300, 400};

    // for_each has another flavour
    // for_each_n
    // c++20

    // transform

    std::cout << "\nmax possible size "
              << list.max_size() << std::endl;

    std::cout << "\nlist size "
              << list.size() << std::endl;

    list.clear();

    std::cout << "\nafter cleaning list size "
              << list.size() << std::endl;

    list.insert(list.begin(), 1);

    list.push_front(0);

    list.emplace(list.end(), 2);

    print(list);

    list.insert(list.end(), {3, 4});

    print(list);

    list.insert(list.end(), 1, 5);

    print(list);

    list.insert(list.end(), list.begin(), list.end());

    print(list);

    std::cout << std::endl;

    return 0;
}