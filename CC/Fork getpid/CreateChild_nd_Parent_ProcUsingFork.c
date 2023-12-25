#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling for fork failure
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Code for the child process
        printf("Child process is running. PID: %d\n", getpid());
    } else {
        // Code for the parent process
        printf("Parent process is running. PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
    }

    // Code executed by both parent and child processes
    printf("This is common code for both processes. PID: %d\n", getpid());

    return 0;
}
