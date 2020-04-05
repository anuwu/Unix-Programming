#include <stdio.h>
#include <sys/file.h>

int main ()
{
	int fd1, fd2 ;
	fd1 = creat ("f1.txt" , 0777) ;
	fd2 = creat ("f2.txt" , 0777) ;

	printf ("The file descriptors are = %d and %d" , fd1, fd2) ;
	return 0 ;
}