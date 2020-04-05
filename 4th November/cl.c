#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	int fd1, fd2, fd3 ;
	fd1 = open ("txt1.txt" , O_RDONLY | O_CREAT , 0444) ;
	fd2 = open ("txt2.txt" , O_RDONLY | O_CREAT , 0444) ;		//On running the program a second time, this fd is -1

	printf ("The FDs are %d and %d\n" , fd1, fd2) ;

	printf ("Closing %d\n" , close (fd1)) ;
	fd3 = open ("txt3.txt" , O_RDONLY | O_CREAT , 0777) ;

	printf ("The FD is %d\n" , fd3) ;		//3

	return 0 ;
}