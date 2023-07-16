#include <iostream>
#include <future>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    std::future<int> result = std::async(sum, 4, 5);

    // Do other work concurrently

    int sumResult = result.get(); // Get the result when it becomes available

    std::cout << "Sum result: " << sumResult << std::endl;

    return 0;
}
