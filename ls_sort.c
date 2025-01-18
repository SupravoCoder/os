//Write a c program to implement the operation ------- ls| sort. 
//The program should execute the ls command and the output of the ls command should be given as input to the sort command.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    if(fork() == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", NULL);
    } else {
        wait(NULL);
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("sort", "sort", NULL);
    }
    return 0;
}
// In this program, we first create a pipe using the pipe() system call.
// Then we fork a child process. In the child process, we close the read end of the pipe and duplicate the write end of the pipe to the standard output using the dup2() system call.
// Then we execute the ls command using the execlp() system call. The output of the ls command is written to the write end of the pipe.
// In the parent process, we wait for the child process to finish using the wait() system call.
// Then we close the write end of the pipe and duplicate the read end of the pipe to the standard input using the dup2() system call.
// Finally, we execute the sort command using the execlp() system call. The sort command reads the output of the ls command from the read end of the pipe and sorts it.
// The ls| sort operation is implemented successfully using pipes and fork-exec in this program.

