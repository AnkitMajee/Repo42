#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This is the child process
        printf("Child Process\n");
    } else if (pid > 0) {
        // This is the parent process
        printf("Parent Process\n");
    } else {
        // An error occurred during fork
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
