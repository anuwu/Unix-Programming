#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main ()
{
	int fd = open ("file.txt" , O_RDWR) ;
	char buf[7] ;

	read (fd , buf, 6) ;
	write (1 , buf , 6) ;

	return 0 ;
}