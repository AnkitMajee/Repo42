#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        // Error handling if fork fails
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // Code executed by child process
        printf("Child process: My PID is %d\n", getpid());
    } else {
        // Code executed by parent process
        printf("Parent process: My PID is %d, Child PID is %d\n", getpid(), child_pid);

        // Introduce a small delay to allow child to print its message first
        sleep(1);
    }

    return 0;
}


// The above and may not run in VScode or other id but will work in Ubantu cmd


//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//
//int main() {
//    pid_t child_pid;
//
//    // Fork a child process
//    child_pid = fork();
//
//    if (child_pid == -1) {
//        // Error handling if fork fails
//        perror("Fork failed");
//        return 1;
//    }
//
//    if (child_pid == 0) {
//        // Code executed by child process
//        printf("Child process: My PID is %d\n", getpid());
//    } else {
//        // Code executed by parent process
//        printf("Parent process: My PID is %d, Child PID is %d\n", getpid(), child_pid);
//    }
//
//    return 0;
//}
