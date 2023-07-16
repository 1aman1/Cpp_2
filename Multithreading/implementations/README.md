
/*
> the CV allows running threads to wait on some conditions and once the condition is satisfied the waiting thread can be notified to awaken by the help of notify_one / notify_all
> a mutex is needed to use CV mechanism
> Three things happen if a thread wants to wait on some condition
>> acquire lock using mechanism like unique lock
>> use wait/ wait for / wait until, this wait operation atomically releases the mutex and suspends the thread
>> when the CV is notified, the thread awakens and reacquires the mutex lock, after that it rechecks the condition to verify if this was a spuriouos call to CV.
*/


sleep

I am done with my timeslice, please dont give me another one until N milliseconds
while sleeping, the thread can hold the lock entire duration.

wait

I am done with my timeslice, please dont give me another one until someone calls notify_one/all()
While waiting, the thread releases the lock and waits until notified again.


Whether to use a semaphore or a condition variable depends on the specific requirements of your multi-threaded program. Both synchronization mechanisms have their own characteristics and are suited for different scenarios.

A semaphore is a synchronization primitive that allows controlling access to a shared resource with a certain capacity. It maintains a count that can be incremented or decremented. Threads can acquire or release the semaphore to control access to the shared resource. Semaphores can be useful when you need to limit the number of threads that can access a resource concurrently, or when you want to signal and wait for a certain number of events to occur.

On the other hand, a condition variable is a synchronization primitive that allows threads to wait until a certain condition is met. It is typically used in conjunction with a mutex to protect the shared data that the condition depends on. Threads can wait on the condition variable until another thread signals or broadcasts that the condition is satisfied. Condition variables are useful when you need threads to synchronize based on specific conditions rather than just acquiring or releasing a resource.

If you simply need to control access to a shared resource and limit the number of concurrent accesses, a semaphore can be a suitable choice. However, if you have more complex synchronization requirements where threads need to wait until certain conditions are met, a condition variable in combination with a mutex is more appropriate.

In the example you provided earlier, where two threads print numbers in a specific order, a condition variable is more suitable. The condition variable allows one thread to wait until it is its turn to print, while the other thread signals that it has finished printing. A semaphore would not be as suitable in this scenario.

It's worth noting that C++ provides std::condition_variable as a built-in synchronization primitive, while semaphores are not part of the C++ Standard Library. However, you can implement semaphores using condition variables and mutexes if needed.

Consider the specific requirements and synchronization needs of your program, and choose the synchronization mechanism that best matches those requirements.