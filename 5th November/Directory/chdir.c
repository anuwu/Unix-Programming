#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//chdir needs entire pathname

int main ()
{
	char cwd[256] ;

	if (chdir("/allah") != 0)
		printf ("Error in changing directory\n") ;
	else
	{
		if (getcwd(cwd , 256) == NULL)
			printf ("Error in getcwd\n") ;
		else
			printf ("%s\n" , cwd) ;
	}

	return 0 ;
}