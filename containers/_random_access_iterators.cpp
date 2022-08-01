#include <iostream>
#include <vector>
#include <algorithm>
// #include<iterator>

void print(const auto &list, bool forward = true)
{
    std::cout << std::endl;
    std::for_each(list.begin(), list.end(), [](const int &i)
                  { std::cout << i << " : "; });
    std::cout << std::endl;
}

void print_itr(const auto &itr, int line)
{
    std::cout << line << " "
              << *itr
              << std::endl;
}

int main()
{

    typedef std::vector<int> container;

    container C1 = {200, 304, 404, 500};

    print(C1);

    auto itr = C1.begin();

    print_itr(itr, __LINE__);

    ///////////////////////////
    // next
    ///////////////////////////

    itr = std::next(itr);
    print_itr(itr, __LINE__);

    itr = std::next(itr, 2);
    print_itr(itr, __LINE__);

    ///////////////////////////
    //  prev
    ///////////////////////////

    itr = std::prev(itr);
    print_itr(itr, __LINE__);

    ///////////////////////////
    // advance
    ///////////////////////////

    itr = C1.begin();
    // next and prev do not actually modify the iterator, but 'advance' does

    print_itr(itr, __LINE__);
    std::advance(itr, 1);
    print_itr(itr, __LINE__);

    // better version, 
    // checks whichever comes first, steps or bound !

    print_itr(itr, __LINE__);
    std::advance(itr, 2, C1.end());
    print_itr(itr, __LINE__);

    ///////////////////////////
    // distance
    ///////////////////////////

    std::cout << std::distance(itr, C1.end());
    std::cout << std::endl;

    itr = std::prev(itr, 1);

    std::cout << std::distance(itr, C1.end());

    std::cout << std::endl;

    return 0;
}