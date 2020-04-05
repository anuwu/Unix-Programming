#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int fd , cop ;
	char *buf_og = " This is the og sentence!" ;
	char *buf_cop = " This is the fake sentence!" ;
	//fd = open ("one.txt" , O_WRONLY | O_APPEND) ;	//If file is not created from before and this is used, then error!
	fd = open ("one.txt" , O_WRONLY | O_APPEND | O_CREAT , 0777) ;

	if (fd < 0)
	{
		printf ("Error!\n") ;
		exit(0) ;
	}

	cop = dup (fd) ;
	printf ("The file descriptors are %d and %d\n" , fd, cop) ;
	write (fd ,buf_og, strlen(buf_og)) ;
	write (cop, buf_cop, strlen(buf_cop)) ;

	return 0 ;
}