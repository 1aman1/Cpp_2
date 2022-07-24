#include <iostream>
#include <thread>

/*
a std::cout resource fight goes here, on each executio the output comesout different.
*/

void printer()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << ":"
                  << std::this_thread::get_id()
                  << std::endl;
    }
}

int main()
{
    std::thread t1(printer);
    std::thread t2(printer);
    t1.join();
    t2.join();

    std::cout << "main thread \n";

    return 0;
}