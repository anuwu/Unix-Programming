#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	printf ("I am %d\n" , (int)getpid()) ;

	pid_t pid = fork () ;
	printf ("Fork returned %d\n" , (int)pid) ;

	if (pid < 0)
	{
		perror ("Fork failed\n") ;
	}
	else if (pid == 0)
	{
		printf ("I am the child with pid %d\n" , (int)getpid()) ;
	}
	else
	{
		printf ("I am the parent\n") ;
	}

	return 0 ;
}

/*
I am 24726
Fork returned 24727
I am the parent
Fork returned 0
I am the child with pid 24727
*/