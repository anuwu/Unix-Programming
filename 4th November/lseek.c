#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	char buff[11] ;
	int fd, rd , wr , rd_last ;
	int fdw ;

	fd = open ("boh.txt" , O_RDONLY) ;
	fdw = creat ("out.txt" , 0777) ;
	if (fd < 0)
	{
		printf ("Error opening file") ;
		exit (0) ;
	}

	int i = 1 ;
	while ((rd = read (fd , buff , 10)) == 10)
	{
		printf ("%d %d %s\n" , i, rd, buff) ;
		wr = write (fdw, buff , 10) ;
		i++ ;
	}

	lseek(fd , -rd , SEEK_CUR) ;
	rd_last = rd ;
	rd = read (fd , buff, rd_last) ;
	wr = write (fdw , buff, rd_last) ;

	return 0 ;
}