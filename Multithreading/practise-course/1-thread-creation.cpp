#include <iostream>
#include <thread>

void func()
{
    std::cout << "new thread\n";
}

int main()
{
    // pass address of the function, a new thread is created here.
    std::thread T(func);
    // std::thread T(&func); //- this is also valid

    if (T.joinable())
        T.join();
    else
        std::cout << "not joinable\n";

    return 0;
}