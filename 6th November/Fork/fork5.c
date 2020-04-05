#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main ()
{
	for (int i = 1 ; i <= 4 ; i++)
	{
		fork () ;
		printf ("%d : MY PID = %d\n" , i , (int)getpid()) ;
	}

	//printf ("Sleeping...\n") ;
	//sleep (1) ;
	printf ("--> MY PID = %d\n" , (int) getpid()) ;

	return 0 ;
}