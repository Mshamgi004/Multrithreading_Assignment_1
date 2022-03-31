// Multithreading Assignmenet - 1 //
// Q.4 //
// Write a program, which get and set pthread scheduling policy and priority. //
// MAHADEV G I //


#include<pthread.h>
#include<stdio.h>

void *my(void *i)
{
    printf("\n I am in %d Thread \n", (int *)i);
}

int main()
{
    pthread_t tid;                                  // Pthread declaration
    struct sched_param param;                       
    int priority, policy, ret;                      
    
    ret = pthread_getschedparam (pthread_self(), &policy, &param);             // return the policy and priority values using pthread_self() function
    
    printf("\n ----------Main THread---------\n Policy: %d \tPriority : %d\n", policy,param.sched_priority);
    
    policy = SCHED_FIFO;                                // SCHED_FIFO for setting the real-time policy
    param.sched_priority = 3;                           // setting the policy value = 3
    
    pthread_setschedparam(pthread_self(), policy, &param);             // setting the scheduling policy and priority of the threads
    
    pthread_getschedparam(pthread_self(), &policy, &param);            // retreiving the sched param for the process
    
    printf("\n ----------Main THread---------\n Policy: %d \tPriority : %d\n", policy,param.sched_priority);
    
    return 0;
}    
    