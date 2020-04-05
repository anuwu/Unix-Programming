#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int fd1, fd2 ;
	fd1 = open ("txt1.txt" , O_RDONLY | O_CREAT , 0444) ;
	fd2 = open ("txt2.txt" , O_RDONLY | O_CREAT , 0000) ;

	printf ("The FDs are %d and %d" , fd1, fd2) ;

	return 0 ;
}