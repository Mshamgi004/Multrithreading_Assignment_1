// Multithreading Assignment - 1 //
// Q.3 //
// Write a pthread program that implements simple initialization code. //
// MAHADEV G I //



#include<stdio.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;             // Pthread once called

void *myinit()
{
     printf("\n I am in init fun\n");
}

void *mythread(void *i)
{
     printf("\n I am in mythread: %d\n", (int *)i);
     pthread_once(&once,(void *)myinit);                 //  Initializisng the pthread
     
     printf("\n Exit from mythread : %d/n", (int *) i);
}

int main()
{
     pthread_t thread, thread1, thread2;                        // Pthreads 1,2,3 declaration
     
     pthread_create(&thread, NULL, mythread,(void *)1);          // Pthread 1 cretion
     
     pthread_create(&thread1, NULL, mythread,(void *)2);         // Pthread 2 creation
     
     pthread_create(&thread2, NULL, mythread,(void *)3);         // Pthread 3 creation
     
     printf("\n Exit from main thread\n");
     
     pthread_exit(NULL);                                       // Exit from the main thread
}     
     