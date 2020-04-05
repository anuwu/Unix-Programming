#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int i = 0 ;

void doSomeWork (char *name)
{
	const int NUM = 5 ;
	for ( ; i < NUM ; i++)
	{
		sleep (rand() % 2) ;
		printf ("Done pass %d for %s\n" , i, name) ;
	}
}

int main ()
{	
	printf ("I am %d\n" , (int)getpid()) ;


	pid_t pid = fork () ;
	srand ((int) pid) ;
	printf ("Fork returned %d\n" , (int)pid) ;

	if (pid < 0)
	{
		perror ("Fork failed\n") ;
	}
	else if (pid == 0)
	{
		printf ("I am the child with pid %d\n" , (int)getpid()) ;
		doSomeWork ("Child") ;
		exit (44) ;
	}

	printf ("I am the parent, waiting for child to finish\n") ;		//Parent ending will ALWAYS be the last statement

	doSomeWork("Parent") ;
	int status = 0 ;
	pid_t child_pid = wait (&status) ;
	printf ("Parent knows child %d finished with status %d\n" , (int)child_pid, status) ;

	return 0 ;
}