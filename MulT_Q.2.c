// Multithreading Assignment - 1 //
// Q.2 //
// Write a program where a structure of information passed to pthread task function, and display structure of information. //
// MAHADEV G I //


#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct info
{
	int roll ;
	char name[20];
	int marks;
};

void *func_task(void *args)
{
	printf("In function task\n");

	struct info *s = (struct info *)args;

	printf("Roll no: %d\t Name of Student: %s\t Marks obtained: %d\n",s->roll, s->name, s->marks);

	return NULL;
}

int main()
{
	struct info st;

	pthread_t tid;

	st.roll = 4;
	strcpy(st.name, "MAHADEV G I");
	st.marks = 88;

	pthread_create(&tid, NULL, func_task, &st);
	pthread_join(tid, NULL);

	pthread_exit(NULL);

	return 0;
}
