#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 100
#define STDOUT 1

int main(int argc, char *argv[])
{
	int pfd[2];
	char buf[BUF_SIZE];
	ssize_t numRead;

	if (argc != 2 || strcmp(argv[1], "--help") == 0)
		printf("%s %s \n", argv[0],argv[1]);

	if (pipe(pfd) == -1)
		printf("failed to create pipe\n");
	else
		printf("Pipe created successfully\nread file des = %d, write file des = %d\n",pfd[0],pfd[1]);

	switch (fork()) 
	{
		case -1:
			printf("failed to fork\n");
		case 0:
			/* Child - reads from pipe */
			printf("Child Created.........%d\n",getpid());

			if (close(pfd[1]) != 0)
				printf ("failed to close write end in - child\n")

			numRead = read(pfd[0], buf, BUF_SIZE);
			printf("text read from pipe by child : %s , numRead = %d\n",buf,numRead);

			if (numRead == -1)
				printf("read error\n");

			if (numRead == 0)
				break; /* End-of-file */

			if (write(STDOUT, buf, numRead) != numRead)
				printf("child - partial/failed write\n");

			write(STDOUT, "\n", 1);

			if (close(pfd[0]) == -1)
				printf("failed to close");
			
			exit(EXIT_SUCCESS);
		default:
			/* Parent - writes to pipe */
			printf("Parent continues %d\n",getpid());

			if (close(pfd[0]) == -1)	/* Read end is unused */
				printf("failed to close read end in - parent\n");

			if(write(pfd[1],argv[1],strlen(argv[1]))!=strlen(argv[1]))	
				printf("parent - partial/failed write\n");
			else
				printf("Parent successfully write to pipe (%d): %s\n",pfd[1],argv[1]);

			if (close(pfd[1]) == -1) 
				printf("failed to close");

			wait(NULL);
			printf ("ALWAS LAST STATEMENT\n") ;
	} 
}