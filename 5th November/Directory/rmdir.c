#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//rmdir needs entire pathname


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
	mkdir ("/hello" , 0777) ;

	loop () ;

	rmdir ("/hello") ;

	return 0 ;
}