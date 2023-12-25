#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Get the process ID of the parent process
    pid_t parent_pid = getpid();

    printf("Parent Process ID: %d\n", parent_pid);

    // Fork a child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        // Forking failed
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // Code executed by child process
        printf("Child Process ID: %d\n", getpid());
        printf("Child's Parent Process ID: %d\n", getppid());
    } else {
        // Code executed by parent process
        printf("Parent Process continues, Child Process ID: %d\n", child_pid);
    }

    return 0;
}
