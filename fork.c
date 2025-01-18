#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls' command\n", getpid());
        execlp("ls", "ls", NULL);
        // If execlp fails
        perror("execlp failed");
        exit(1);
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to complete
        printf("Parent process (PID: %d) finished\n", getpid());
    }

    return 0;
}