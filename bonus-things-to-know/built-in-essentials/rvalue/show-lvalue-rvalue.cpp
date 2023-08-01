#include <iostream>
#include <utility> // For std::forward

// Function template that takes a universal reference as a parameter
template <typename T>
void process(T &&value)
{
    // Inside this function, 'value' is a universal reference

    // Check if 'value' is an lvalue or an rvalue
    if constexpr (std::is_lvalue_reference_v<decltype(value)>)
    {
        std::cout << "Processing lvalue: " << value << std::endl;
    }
    else
    {
        std::cout << "Processing rvalue: " << value << std::endl;
    }
}

int main()
{
    int x = 42;

    // Call the 'process' function with an lvalue
    process(x); // 'x' is an lvalue

    // Call the 'process' function with an rvalue (temporary)
    process(123); // 123 is an rvalue

    // Use std::forward to preserve the value category (lvalue or rvalue)
    int y = 88;
    process(std::forward<int>(y)); // 'y' is an lvalue

    return 0;
}
