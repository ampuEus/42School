# Deadlock

A deadlock occurs when two threads each lock a different variable at the same time and then try to lock the variable that the other thread already locked. As a result, each thread stops executing and waits for the other thread to release the variable. Because each thread is holding the variable that the other thread wants, nothing occurs, and the threads remain deadlocked.

On the above gif 2 processes are competing for 2 resources in opposite order. These are the different cases that can occur:
  - **(A)** A single process goes through
  - **(B)** The later process has to wait
  - **(C)** A deadlock occurs when the first process locks the first resource at the same time as the second process locks the second resource
  - **(D)** The deadlock can be resolved by cancelling and restarting the first process.

![Two processes competing for two resources in opposite order](../img/deadlock_2Thread.gif)
