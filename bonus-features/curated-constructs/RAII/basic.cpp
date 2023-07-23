#include <iostream>
#include <memory>

class Resource
{
public:
    Resource()
    {
        std::cout << "Resource acquired." << std::endl;
    }

    void doSomething()
    {
        std::cout << "Resource in use." << std::endl;
    }

    ~Resource()
    {
        std::cout << "Resource released." << std::endl;
    }
};

int main()
{
    // Using RAII with std::unique_ptr to manage a Resource
    std::unique_ptr<Resource> resourcePtr = std::make_unique<Resource>();

    // Do something with the resource
    resourcePtr->doSomething();

    // When 'resourcePtr' goes out of scope (e.g., end of function or block),
    // the Resource will be automatically released.
    return 0;
}
