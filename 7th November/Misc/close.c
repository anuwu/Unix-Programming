#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main ()
{
	int fd, len ;
	char *str = "This is the real life" ;
	len = strlen(str) ;

	fd = open ("test.txt" , O_WRONLY | O_CREAT , 0777) ;
	dup2 (fd, 1) ;

	close (1) ;
	printf ("This is the real life!\n") ;
}

/*
Expected result! Nothing is printing in the file, but file is created!
*/