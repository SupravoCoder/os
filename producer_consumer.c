#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int produced_count = 0, consumed_count = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer(void *param) {
    int item;
    while (1) {
        item = rand() % 100; // Produce an item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        if (produced_count >= NUM_ITEMS) {
            pthread_mutex_unlock(&mutex);
            sem_post(&full);
            break;
        }

        // Add the item to the buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        produced_count++;
        printf("Producer produced %d\n", item);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *param) {
    int item;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        if (consumed_count >= NUM_ITEMS) {
            pthread_mutex_unlock(&mutex);
            sem_post(&empty);
            break;
        }

        // Remove the item from the buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        consumed_count++;
        printf("Consumer consumed %d\n", item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    // Initialize the semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create the producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy the semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}