
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