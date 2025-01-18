#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to calculate factorial
void* factorial(void* arg) {
    int n = *((int*)arg);
    int* result = malloc(sizeof(int));
    *result = 1;
    for (int i = 1; i <= n; i++) {
        *result *= i;
    }
    return result;
}

// Function to find the reverse of a number
void* reverse(void* arg) {
    int n = *((int*)arg);
    int* reversed = malloc(sizeof(int));
    *reversed = 0;
    while (n != 0) {
        *reversed = *reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    pthread_t thread1, thread2;
    int number = 15; // Example number
    int* factorial_result, *reverse_result;

    // Create thread to calculate factorial
    pthread_create(&thread1, NULL, factorial, &number);

    // Create thread to find reverse
    pthread_create(&thread2, NULL, reverse, &number);

    // Wait for threads to finish
    pthread_join(thread1, (void**)&factorial_result);
    pthread_join(thread2, (void**)&reverse_result);

    printf("Factorial of %d is %d\n", number, *factorial_result);
    printf("Reverse of %d is %d\n", number, *reverse_result);

    // Free the dynamically allocated memory
    free(factorial_result);
    free(reverse_result);

    return 0;
}
