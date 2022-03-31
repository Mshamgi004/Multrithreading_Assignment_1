// Multithreading Assignment - 1 //
// Q.1 //
// Write a pthread application where main task terminated but pending pthreads task still execute.//
// MAHADEV G I //


#include<stdio.h>
#include<pthread.h>

void *thread_func(void *arg)
{
	printf("thread function execution\n");

	for(int i=0; i<20; i++)
		printf("Value of i: %d\n",i);

	printf("Exiting thread from the process\n");
}

int main()
{
	pthread_t tid;             // Creation of pthread
	int ret=0;

	pthread_create(&tid, NULL, thread_func, NULL);     // Pthread creation

	pthread_join(tid, NULL);                        // Pthread joining

	pthread_exit(NULL);                           // Pthread exiting 
	printf("Main thread terminated from the process\n");

	return 0;
}