#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Code executed by the child process

        // Display a message from the child
        printf("Child process: My PID is %d\n", getpid());

        // Execute a new program in the child process
        execlp("/bin/ls", "ls", "-l", NULL);

        // If execlp fails, the code below will be executed
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Code executed by the parent process

        // Wait for the child process to finish
        wait(NULL);

        // Display a message from the parent
        printf("Parent process: Child process completed\n");
    }

    return 0;
}
