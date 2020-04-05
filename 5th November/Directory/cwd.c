#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>



int main ()
{
	long max ;
	char *buf ;

	max = pathconf ("/" , _PC_PATH_MAX) ;
	buf = (char *) malloc (max) ;

	printf ("The max length is %li\n" , max) ;

	if (getcwd(buf,max) == NULL)
	{
		printf("Could not obtain working directory\n") ;
	}
	else
	{
		printf ("%s\n" , buf);
	}

	return 0 ;
}