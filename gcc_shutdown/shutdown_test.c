#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;

	pid = fork();
	if(pid == 0)
	{
//		execl("/bin/ls","ls","-l", (char*)0);
		execl("/sbin/shutdown","shutdown","-r","1",NULL);
		perror("execl failed");
	}
	else if(pid > 0)
	{
		wait((int*)0);
		printf("ls completed\n");
		exit(0);
	}
	else
	{
		perror("fork failed");
	}
}
