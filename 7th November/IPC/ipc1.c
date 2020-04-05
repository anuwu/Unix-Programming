#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//Child writes and parent reads.

int main ()
{
	int fedes[2] ;
	char buf[30] ;

	pipe (fedes) ;

	if (fork())
	{
		wait (NULL) ;
		printf ("Parent reading from pipe\n") ;
		read (fedes[0] , buf, 5) ;
		printf ("Parent read : %s\n" , buf) ;
	}
	else
	{
		printf ("Child writing to the pipe\n") ;
		write (fedes[1], "test", 5) ;
		printf ("Child exiting\n") ;
		exit (0) ;
	}

	return 0 ;
}

