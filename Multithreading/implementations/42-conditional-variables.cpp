#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isDataReady = false;
int sharedData = 0;

void producerFunction()
{
    std::lock_guard<std::mutex> lock(mtx);

    sharedData = 42;
    isDataReady = true;

    cv.notify_one();
}

void consumerFunction()
{
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [] { return isDataReady; });

    std::cout << "Consumer: Data received: " << sharedData << std::endl;
}

int main()
{
    std::thread producer(producerFunction);
    std::thread consumer(consumerFunction);

    producer.join();
    consumer.join();

    return 0;
}
