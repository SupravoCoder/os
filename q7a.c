//Write a c program to create a thread from main thread and then print the thread id and process id of that newly 
//created thread and main thread. 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) // Thread function to print thread ID and process ID
{
    printf("Thread ID: %lu\n", pthread_self());
    printf("Process ID: %d\n", getpid());
    return NULL;
}

int main() // Main function to create a thread and print thread ID and process ID of main thread
{
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    printf("Main Thread ID: %lu\n", pthread_self());
    printf("Main Process ID: %d\n", getpid());
    pthread_join(thread, NULL);
    return 0;
}

