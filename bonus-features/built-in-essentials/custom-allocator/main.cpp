#include <iostream>
#include <vector>

using namespace std;

template <typename type>
struct MyCustomAlloc : allocator<type>
{
    type *allocate(size_t size)
    {
        cout << "Allocation request size : " << size << endl;
        return new type[size];
        // return allocator<type>::allocate(size);
    }
};

int main()
{
    vector<int, MyCustomAlloc<int>> container;

    container.reserve(1);

    container.push_back(1);
    container.push_back(11);
    container.push_back(111);

    return 0;
}