#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	int fd ;
	fd = open(argv[1] , O_WRONLY) ;
	if (fd == -1)
	{
		printf ("Error opening file") ;
		exit (0) ;
	}

	printf ("FD = %d\n" , fd) ;

	return 0 ;
}