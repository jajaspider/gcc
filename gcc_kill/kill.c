#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argv, char *argc[])
{
	if(argv < 2)
	{
		printf("enter the process pid\n");
		exit(1);
	}

	pid_t pid;

	pid = fork();
	if(pid == 0)
	{
		execl("/bin/kill", "kill", "-15", argc[1], NULL);
		perror("execl failed");
	}
	else if(pid > 0)
	{
		wait((int*)0);
		printf("process kill completed\n");
		exit(0);
	}
	else
	{
		perror("fork failed");
	}
}
