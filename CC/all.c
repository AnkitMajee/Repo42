// write a C program to create a child process using fork() function
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	fork();
	printf("Hello World!!")
	return 0;
}

// write a C program to create a child process that takes the value from parent process and do that calculation in the child process and pring the value
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int n = 1;
	pid = fork(); // child process
	if (pid == 0)
	{
		printf("child value: %d\n", ++n);
		exit 0;
	}
	printf("parent value: %d\n", --n);
}

//write a C program to display the parent pid and child pid.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		printf("child pid: %d\n", getpid());
		exit(0);
	}
	else
	{
		printf("parent pid: %d\n", getppid());
		exit(0);
	}
}

//create a 7 child process without using any loop and show the pid's of both parent and child processes

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
	fork();
	fork();
	fork();
	printf("parent pid: %d, child pid: %d\n", getppid(), getpid());	
}


//write a C program to creat a zombie process using the following fuctions: getchar, sleep

//using getchar
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int child_pid = fork();
	if (child_pid > 0)
	{
		getchar();
	}
	else
		exit(0);
}

//using sleep
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

oid main()
{
	int child_pid = fork();
	if (child_pid > 0)
	{
		sleep(0);
	}
	else
		exit(0);
}

//write a c program to create a child process kill it and check the status of the process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		pause();
		exit(0);
	}
	printf("pid: %d", getchar());
	kill(pid, SIGKILL);
	exit(0);
	
	return 0;

}