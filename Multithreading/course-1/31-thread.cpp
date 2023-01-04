#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

int main()
{
    std::vector<std::thread> threadArray;

    for (int i = 0; i < 5; ++i)
    {
        threadArray.push_back(std::thread(
            [i]()
            {
                /*The output could be different for each run, which demonstrates the non-deterministic nature of concurrent programming. Also, we can see from the output, even in-between the print statement, it could be preemptive, in other words, the scheduler can interrupt at any time. So, our additional effort of using the capture feature of lambda [i] was not successful due to the nature of current programming*/
                std::cout << "new thread "
                          << i
                          << std::endl;
            }));
    }

    std::for_each(threadArray.begin(), threadArray.end(), [](std::thread &t)
                  {
                        if (t.joinable())
                        {
                            t.join();
                        } });

    std::cout << "main thread \n";

    return 0;
}