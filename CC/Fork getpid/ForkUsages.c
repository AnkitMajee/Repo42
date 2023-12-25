#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a new process
    child_pid = fork();

    if (child_pid == -1) {
        // Fork failed
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process: PID = %d\n", getpid());
    } else {
        // This code is executed by the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);
    }

    // Both the parent and child processes continue executing from here
    printf("This is printed by both parent and child processes.\n");

    return 0;
}
