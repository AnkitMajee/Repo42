#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID: %d)\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID: %d)\n", getpid());
        printf("Child process ID: %d\n", pid);
    }

    return 0;
}
