#include <iostream>
#include <thread>

class sth
{
public:
    void threadF()
    {
        for (int i = 0; i < 100000; ++i)
        {
        }
        std::cout << "new thread\n";
    }
};

int main()
{
    sth obj;
    // pass address of the function, a new thread is created here.

    std::thread t(sth);

    // for the parent/main thread to wait for new child thread
    // , before the parent thread gets terminated, USE
    // t.join();

    // for the parent/main thread to free the new child thread
    // and continue execution, USE
    t.detach();

    if (t.joinable())
        t.join();
    else
        std::cout << "not joinable\n";

    return 0;
}