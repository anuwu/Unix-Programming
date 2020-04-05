/*
EFFECT NOT OBSERVED
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


void loop ()
{
		char ch ;

		while (1)
		{
			printf ("Press p to proceed\n") ;
			scanf("%[^\n]%*c", &ch);  ;
			if (ch == 'p') 
				break ;
		}
}

int main ()
{
	int fd = open ("urkund.txt" , O_RDWR) ;

	loop () ;
	write (fd , "HELLO!" , 6) ;
	loop () ;

	close (fd) ;
}
