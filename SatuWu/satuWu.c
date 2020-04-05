#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{	
	int i, n = 3 ;
	for (i = 0 ; i < n ; i++)
	{
		fork() ;
	}

	printf ("F ") ;

	return 0 ;
}