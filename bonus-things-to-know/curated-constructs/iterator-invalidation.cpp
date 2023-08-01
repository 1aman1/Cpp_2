#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    // Fill the vector with some values
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // Let's create an iterator and point it to the second element
    std::vector<int>::iterator it = numbers.begin() + 1;

    // Print the current element that the iterator points to
    std::cout << "Current element: " << *it << std::endl;

    // Now, let's add an element to the vector. This may cause reallocation.
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);

    // Try to print the element using the iterator again.
    // This may lead to undefined behavior since the iterator might have been invalidated.
    std::cout << "Current element after modification: " << *it << std::endl;

    return 0;
}
