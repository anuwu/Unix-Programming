#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void loop ()
{
		char ch ;

		while (1)
		{
			printf ("Press p to proceed\n") ;
			scanf ("%c" , &ch) ;
			if (ch == 'p') 
				break ;
		}
}

int main ()
{
	int fd = open ("urkund.txt" , O_RDWR | O_CREAT , 0777) ;

	loop () ;
	unlink ("urkund.txt") ;
	loop () ;

	return 0 ;
}